#include <math.h>
#include "parameters.h"
#include "time_compute.h"

// Check if a number is prime
int square_root_ceil(unsigned long long int n)
{
    int s = (int)ceil(sqrt(n));
    for (int i = 2; i < s; i++)
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
    TIME_COMPUTE(square_root_ceil, parm);         // Do the test
}