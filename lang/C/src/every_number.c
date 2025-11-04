#include <stdio.h>
#include <sqlite3.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "parameters.h"
#include "compute.h"
#include "database.h"

// Check if a number is prime
int every_number(unsigned long long int n)
{
    // Check for every number until it reteach the max value or find a good value
    for (unsigned long long int i = 2; i < n; i++)
    {
        if ((n % i) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    // Set parameters
    parameters parm = parameters_set(argc, argv); // Set parameters for the test

    // Open database
    sqlite3 *db = NULL;
    mkdir("./build", 0777); // Create the dir if it doesn't exist.
    mkdir("./build/db", 0777);
    if (database_open("./build/db/every_number.db", &db) != SQLITE_OK)
    {
        return 1;
    }

    // Compute numbers
    compute(every_number, parm, &db);

    // End of program
    database_print(&db);
    sqlite3_close(db);
}