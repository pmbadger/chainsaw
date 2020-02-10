#ifndef TEST_LOADED 
#define TEST_LOADED

#include <stdio.h>
#include <stdbool.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define RESET "\x1B[0m"

#define PASS "PASS!"
#define FAIL "FAIL!"
#define DEFAULT_ASSERT_MESSAGE "Assertion failed!"

#define draw(COLOR, TEXT) COLOR TEXT RESET

bool assert(bool expression, const char* message);

void unit_test(bool expression, const char* subject);

double coverage();

bool all_pass();

bool report();

#endif 
