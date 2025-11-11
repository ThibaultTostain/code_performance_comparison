#define _GNU_SOURCE // used for strdup()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Default values for the tests
#define START_DEFAULT 2
#define END_DEFAULT 10000000
#define DIVISOR_DEFAULT 1000
#define REP_DEFAULT 10
#define MAX_TIME_DEFAULT 1
#define TYPE_DEFAULT "linear"

#ifndef PARAMETERS_H
#define PARAMETERS_H
typedef struct
{
    unsigned long long int start, end;
    unsigned int divisor, rep, max_time;
    char *type;
    /*
    start: minimal value for the test
    end: maximum value for the test
    divisor: number of value tested between the start and end value
    rep: number of repetition of the verification during the test, higher give more accurate result but increase the time of compute
    max_time : maximum time for a verification, if it's reach this value for one verification, the programme stop
    type : type of output "linear" or "log10"
    */
} parameters;
#endif

void parameters_print(parameters *p);
parameters parameters_default();
parameters parameters_set(int argc, char *argv[]);
int parameters_check(parameters parm);