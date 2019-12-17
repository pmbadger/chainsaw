#include "unittest/unittest.h"


bool assert(bool expression, const char* message) {
    if (!expression) {
        printf("%s\n", DEFAULT_ASSERT_MESSAGE);
        printf("%s\n", message);
    }
}

void unit_test(bool expression, const char* subject) {
    TOTAL++;
    printf("%d. %s: %s\n", TOTAL, subject, expression? PASS : FAIL);
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
    printf("%s ", all_pass()? "All checks successful!" : "Some tests have failed");
    printf("[%d / %d]\n", SUCCESS, TOTAL);
    printf("Total coverage: %.2f%\n", coverage());
    return TOTAL - SUCCESS;
}

