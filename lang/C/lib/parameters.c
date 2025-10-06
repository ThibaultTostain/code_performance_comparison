#include "parameters.h"

// Print values of the parameters
void parameters_print(parameters *p)
{
    printf("== Parameters ==\n");
    printf("START : %llu\n", p->start);
    printf("END : %llu\n", p->end);
    printf("STEP : %d\n", p->step);
    printf("REP : %d\n", p->rep);
    printf("Max_TIME : %ds\n", p->max_time);
    printf("\n");
}

// Set value for parameters, if the specification is not reteach, it's set to the default values
parameters parameters_set(int argc, char *argv[])
{
    parameters parm;
    if (argc == 6)
    {
        char *endptr_1;
        char *endptr_2;
        parm = (parameters){strtoull(argv[1], &endptr_1, 10), strtoull(argv[2], &endptr_2, 10), atoi(argv[3]), atoi(argv[4]), atoi(argv[5])};
    }
    else if (argc == 4)
    {
        char *endptr_1;
        char *endptr_2;
        parm = (parameters){strtoull(argv[1], &endptr_1, 10), strtoull(argv[1], &endptr_2, 10), 1, atoi(argv[2]), atoi(argv[3])};
        printf("Run : Test a specific value.\n");
    }
    else
    {
        parm = (parameters){START_DEFAULT, END_DEFAULT, STEP_DEFAULT, REP_DEFAULT, MAX_TIME_DEFAULT};
        printf("Warning : Number of arguments doesn't match the specification. The program will use the default values.\n");
    }
    parameters_print(&parm);
    return parm;
}