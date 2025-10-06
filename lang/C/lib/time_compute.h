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
    float log_start = log10(PARAMETERS.start);                                                                                            \
    float log_end = log10(PARAMETERS.end);                                                                                                \
    float log_step = (log_end - log_start) / (PARAMETERS.step - 1);                                                                       \
                                                                                                                                          \
    /*Compute the function*/                                                                                                              \
    for (int i = 0; i < (PARAMETERS.step); i++)                                                                                           \
    {                                                                                                                                     \
        float log_value = log_start + i * log_step;                                                                                       \
        int value = pow(10, log_value);                                                                                                   \
        clock_t start_time = clock();                                                                                                     \
        int res = 0;                                                                                                                      \
        for (int rep = 0; rep < (PARAMETERS.rep); rep++)                                                                                  \
        {                                                                                                                                 \
            res = FCT(value); /*Add volatile to avoid optimisation because it's unused*/                                                  \
        }                                                                                                                                 \
        clock_t end_time = clock();                                                                                                       \
        double elapsed = (double)(end_time - start_time) / CLOCKS_PER_SEC;                                                                \
        double avg_time = elapsed / (PARAMETERS.rep);                                                                                     \
        printf("%d | %d : %.6fs\n", res, value, avg_time);                                                                                \
        if (avg_time >= (PARAMETERS.max_time))                                                                                            \
        {                                                                                                                                 \
            printf("STOP : avg_time >= MAX_TIME.\n");                                                                                     \
            i = (PARAMETERS.step);                                                                                                        \
        }                                                                                                                                 \
    }
