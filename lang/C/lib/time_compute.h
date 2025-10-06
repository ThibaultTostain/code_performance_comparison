#include <time.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define TIME_COMPUTE(FCT, PARAMETERS)                                                                                                     \
    /* Verify if the interval is valid */                                                                                                 \
    if (PARAMETERS.end < PARAMETERS.start || PARAMETERS.end <= 0 || PARAMETERS.start <= 0 || PARAMETERS.step <= 0 || PARAMETERS.rep <= 0) \
    {                                                                                                                                     \
        printf("Error : END, START, STEP or REP should be greater than 0 or END >= START.\n");                                            \
        return 1;                                                                                                                         \
    }                                                                                                                                     \
                                                                                                                                          \
    /* Initialise values */                                                                                                               \
    long double log_start = log10l(PARAMETERS.start);                                                                                     \
    long double log_end = log10l(PARAMETERS.end);                                                                                         \
    long double log_step = 0;                                                                                                             \
    if (PARAMETERS.step > 1)                                                                                                              \
    {                                                                                                                                     \
        log_step = (log_end - log_start) / (long double)(PARAMETERS.step - 1);                                                            \
    }                                                                                                                                     \
    long double log_value;                                                                                                                \
    unsigned long long int value;                                                                                                         \
                                                                                                                                          \
    /*Compute the function*/                                                                                                              \
    for (unsigned int i = 0; i < (PARAMETERS.step); i++)                                                                                  \
    {                                                                                                                                     \
        if (PARAMETERS.step == 1)                                                                                                         \
        {                                                                                                                                 \
            value = PARAMETERS.start;                                                                                                     \
        }                                                                                                                                 \
        else                                                                                                                              \
        {                                                                                                                                 \
            log_value = log_start + i * log_step;                                                                                         \
            value = pow(10, log_value);                                                                                                   \
        }                                                                                                                                 \
        clock_t start_time = clock();                                                                                                     \
        int res = 0;                                                                                                                      \
        for (unsigned int rep = 0; rep < (PARAMETERS.rep); rep++)                                                                         \
        {                                                                                                                                 \
            res = FCT(value);                                                                                                             \
        }                                                                                                                                 \
        clock_t end_time = clock();                                                                                                       \
        double elapsed = (double)(end_time - start_time) / CLOCKS_PER_SEC;                                                                \
        double avg_time = elapsed / (PARAMETERS.rep);                                                                                     \
        printf("%d | %llu : %.6fs\n", res, value, avg_time);                                                                              \
        if (avg_time >= (PARAMETERS.max_time))                                                                                            \
        {                                                                                                                                 \
            printf("STOP : avg_time >= MAX_TIME.\n");                                                                                     \
            i = (PARAMETERS.step);                                                                                                        \
        }                                                                                                                                 \
    }
