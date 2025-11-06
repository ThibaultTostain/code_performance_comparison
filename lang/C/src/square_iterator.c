#include <math.h>
#include <stdio.h>
#include <sqlite3.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "parameters.h"
#include "compute.h"
#include "database.h"

// Check if a number is prime
int square_iterator(unsigned long long int n)
{
    for (unsigned long long int i = 2; i * i < n; i++)
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
    if (database_open("./build/db/square_iterator.db", &db) != SQLITE_OK)
    {
        return 1;
    }

    // Compute numbers
    compute(square_iterator, parm, &db);

    // End of program
    database_print(&db);
    sqlite3_close(db);
}