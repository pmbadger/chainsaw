#ifndef TEST_LOADED 
#define TEST_LOADED

#include <stdio.h>
#include <stdbool.h>


const static char* DEFAULT_ASSERT_MESSAGE = "Assertion failed!";
const static char* PASS = "PASS!";
const static char* FAIL = "FAIL!";
static int TOTAL=0, SUCCESS=0;

bool assert(bool expression, const char* message);

void unit_test(bool expression, const char* subject);

double coverage();

bool all_pass();

bool report();

#endif 
