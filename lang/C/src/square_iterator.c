#include <math.h>
#include "parameters.h"
#include "time_compute.h"

// Check if a number is prime
int square_iterator(unsigned long long int n)
{
    for (unsigned long long int i = 2; i * i < n; i++)
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
    TIME_COMPUTE(square_iterator, parm);          // Do the test
}