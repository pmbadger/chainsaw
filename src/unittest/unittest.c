#include "unittest.h"
#include "colors.h"

#define draw(COLOR, TEXT) COLOR TEXT RESET

#define PASS "PASS!"
#define FAIL "FAIL!"
#define DEFAULT_ASSERT_MESSAGE "Assertion failed!"

static int TOTAL = 0;
static int SUCCESS = 0;


bool assert(bool expression, const char* message) {
    if (!expression) {
        printf("%s\n", draw(RED, DEFAULT_ASSERT_MESSAGE));
        printf("%s\n", message);
    }
    return expression;
}

void unit_test(bool expression, const char* subject) {
    TOTAL++;
    printf( "%d. %s: %s\n", TOTAL, subject, expression? draw(GRN, PASS) : draw(RED, FAIL));
    if (expression) { 
        SUCCESS++;
    }
}

double coverage() {
    return 100 * (TOTAL? (double)SUCCESS/TOTAL : 1);
}

bool all_pass() {
    return SUCCESS == TOTAL;
}

bool report() {
    printf("%s ", all_pass()? draw(GRN, "All checks successful!") : draw(RED, "Some tests have failed"));
    printf("[%d / %d]\n", SUCCESS, TOTAL);
    printf("Total coverage: %.2f%%\n", coverage());
    return TOTAL - SUCCESS;
}

