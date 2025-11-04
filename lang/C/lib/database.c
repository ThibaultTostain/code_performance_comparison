#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include "database.h"

// Callback function for SQL queries
static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    (void)NotUsed;
    for (int i = 0; i < argc; i++)
    {
        printf("%s = %s ; ", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

void database_print(sqlite3 **db)
{
    // Read data from the table
    const char *sql_select = "SELECT * FROM is_prime";
    char *err_msg = 0;
    int rc = sqlite3_exec(*db, sql_select, callback, 0, &err_msg);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Failed to select data: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
}

void database_add(sqlite3 **db, unsigned long long int value, double avg_time)
{
    // Insert data into the table
    char sql_insert[256];

    snprintf(sql_insert, sizeof(sql_insert), "INSERT OR IGNORE INTO is_prime (VALUE, TIME) VALUES (%lld, %f);", value, avg_time);

    char *err_msg = 0;
    int rc = sqlite3_exec(*db, sql_insert, 0, 0, &err_msg);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        exit(1);
    }
}

int database_open(char *path, sqlite3 **db)
{
    // Create main variables
    char *err_msg = 0;
    int rc; // retrun code

    // Open connection to the database
    rc = sqlite3_open(path, db);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(*db));
        sqlite3_close(*db);
        return rc;
    }

    // Create the main table if it's not already exist
    const char *sql_create_table =
        "CREATE TABLE IF NOT EXISTS is_prime("
        "VALUE   INTEGER    NOT NULL    UNIQUE,"
        "TIME    REAL       NOT NULL);";
    rc = sqlite3_exec(*db, sql_create_table, 0, 0, &err_msg);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(*db);
        return rc;
    }

    // If the database is create and with the right table, continue
    return SQLITE_OK;
}