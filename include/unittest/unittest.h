#ifndef TEST_LOADED 
#define TEST_LOADED

#include <stdio.h>
#include <stdbool.h>


bool assert(bool expression, const char* message);

void unit_test(bool expression, const char* subject);

double coverage();

bool all_pass();

bool report();

#endif 
