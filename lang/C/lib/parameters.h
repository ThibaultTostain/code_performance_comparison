#include <stdio.h>
#include <stdlib.h>

// Default values for the tests
#define START_DEFAULT 1000000
#define END_DEFAULT 10000000
#define STEP_DEFAULT 15
#define REP_DEFAULT 20
#define MAX_TIME_DEFAULT 1

typedef struct
{
    int start, end, step, rep, max_time;
    /*
    start: minimal value for the test
    end: maximum value for the test
    step: number of value tested between the start and end value
    rep: number of repetition of the verification during the test, higher give more accurate result but increase the time of compute
    max_time : maximum time for a verification, if it's reach this value for one verification, the programme stop
    */
} parameters;

void parameters_print(parameters *p);
parameters parameters_set(int argc, char *argv[]);