#include <sqlite3.h>
#include "compute.h"
#include "parameters.h"
#include "database.h"

void compute(int (*evaluated_function)(unsigned long long int n), parameters parm, sqlite3 **db)
{
    if (strcmp(parm.type, "linear") == 0)
    {
        unsigned long long int step = (parm.end - parm.start) / (parm.divisor);
        for (unsigned long long int value = parm.start; value < parm.end; value += step)
        {
            clock_t start_time = clock();
            int res = 0;
            for (unsigned int rep = 0; rep < parm.rep; rep++)
            {
                res = evaluated_function(value);
            }
            clock_t end_time = clock();
            double elapsed = (double)(end_time - start_time) / CLOCKS_PER_SEC;
            double avg_time = elapsed / parm.rep;
            // printf("%d | %llu : %.6fs\n", res, value, avg_time); // Disable to reduce run time
            if (res == 0)
            {
                database_add(db, value, avg_time);
            }
            if (avg_time >= parm.max_time)
            {
                printf("STOP : avg_time >= MAX_TIME.\n");
                value = parm.end;
            }
        }
    }
    else if (strcmp(parm.type, "log10") == 0)
    {
        /* Initialise values */
        long double log_start = log10l(parm.start);
        long double log_end = log10l(parm.end);
        long double log_step = 0;
        if (parm.divisor > 1)
        {
            log_step = (log_end - log_start) / (long double)(parm.divisor - 1);
        }
        long double log_value;
        unsigned long long int value;

        /*Compute the function*/
        for (unsigned int i = 0; i < (parm.divisor); i++)
        {
            if (parm.divisor == 1)
            {
                value = parm.start;
            }
            else
            {
                log_value = log_start + i * log_step;
                value = pow(10, log_value);
            }
            clock_t start_time = clock();
            int res = 0;
            for (unsigned int rep = 0; rep < (parm.rep); rep++)
            {
                res = evaluated_function(value);
            }
            clock_t end_time = clock();
            double elapsed = (double)(end_time - start_time) / CLOCKS_PER_SEC;
            double avg_time = elapsed / (parm.rep);
            // printf("%d | %llu : %.6fs\n", res, value, avg_time); // Disable to reduce run time
            if (res == 0)
            {
                database_add(db, value, avg_time);
            }
            if (avg_time >= (parm.max_time))
            {
                printf("STOP : avg_time >= MAX_TIME.\n");
                i = (parm.divisor);
            }
        }
    }
    else
    {
        printf("You chose an unknow type, \"%s\" is not a valid type.\n", parm.type);
    }
}