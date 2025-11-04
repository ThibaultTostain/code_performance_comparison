#include "parameters.h"

// Print values of the parameters
void parameters_print(parameters *p)
{
    printf("== Parameters ==\n");
    printf("START : %llu\n", p->start);
    printf("END : %llu\n", p->end);
    printf("DIVISOR : %d\n", p->divisor);
    printf("REP : %d\n", p->rep);
    printf("Max_TIME : %ds\n", p->max_time);
    printf("Type : %s\n", p->type);
    printf("\n");
}

// Check if the value of parameters is correct or not
int parameters_check(parameters parm)
{
    if (parm.start < 1) // Prime numbers is always greater than 1
        return 0;
    if (parm.end < parm.start) // Impossible to end with a smaller value than the first
        return 0;
    if (parm.divisor < 1) // divisor can't be 0 or negative (it's an unsigned, so it will not be negative)
        return 0;
    if (parm.rep < 1) // At least, do one compute
        return 0;
    if (parm.max_time <= 0) // At least, give more than 0s to run the program.
        return 0;
    return 1;
}

// Set value for parameters
parameters parameters_set(int argc, char *argv[])
{
    parameters parm;
    if (argc == 7) // If all the parameters are present, try to set the value
    {
        char *endptr_1;
        char *endptr_2;
        parm = (parameters){strtoull(argv[1], &endptr_1, 10), strtoull(argv[2], &endptr_2, 10), atoi(argv[3]), atoi(argv[4]), atoi(argv[5]), strdup(argv[6])};
        if (!parameters_check(parm))
        {
            printf("Error, please use : %s <start(llu)> <end (llu)> <divisor(u)> <rep(u)> <max_time(u)> <type(char *)>\n", argv[0]);
            exit(1);
        }
    }
    else if (argc == 1) // If no parameters is give, set default value
    {
        printf("Without any arguments, the program will use the default values.\n");
        return (parameters){START_DEFAULT, END_DEFAULT, DIVISOR_DEFAULT, REP_DEFAULT, MAX_TIME_DEFAULT, TYPE_DEFAULT};
    }
    else // Else, exit the program
    {
        printf("Warning : Number of arguments doesn't match the specification.\n");
        printf("%s <start(llu)> <end (llu)> <divisor(u)> <rep(u)> <max_time(u)> <type(char *)>\n", argv[0]);
        exit(1);
    }
    parameters_print(&parm);
    return parm;
}