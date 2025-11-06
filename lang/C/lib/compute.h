#include <time.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include <sqlite3.h>
#include "parameters.h"

void compute(int (*evaluated_function)(unsigned long long int n), parameters parm, sqlite3 **db);
