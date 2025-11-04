#include "parameters.h"
#include "compute.h"

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
    parameters parm = parameters_set(argc, argv); // Set parameters for the test
    compute(every_number, parm);                  // Do the test
}