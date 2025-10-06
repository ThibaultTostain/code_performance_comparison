#include "parameters.h"
#include "time_compute.h"

// Check if a number is prime
int every_number(int n)
{
    // Check for every number until it reteach the max value or find a good value
    for (int i = 2; i < n; i++)
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
    parameters parm = parameters_set(argc, argv); // Set parameters for the test
    TIME_COMPUTE(every_number, parm);             // Do the test
}