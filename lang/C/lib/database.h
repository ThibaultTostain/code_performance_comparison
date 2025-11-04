#include <stdio.h>
#include <sqlite3.h>

void database_print(sqlite3 **db);
void database_add(sqlite3 **db, unsigned long long int value, double avg_time);
int database_open(char *path, sqlite3 **db);