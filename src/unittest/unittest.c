#include "unittest.h"
#include "colors.h"

const char* PASS = "PASS!";
const char* FAIL = "FAIL!";
const char* DEFAULT_ASSERT_MESSAGE = "Assertion failed!";

static int TOTAL = 0;
static int SUCCESS = 0;


bool assert(bool expression, const char* message) {
    if (!expression) {
        printf(RED "%s\n" RESET, DEFAULT_ASSERT_MESSAGE);
        printf(YEL "%s\n" RESET, message);
    }
    return expression;
}

void unit_test(bool expression, const char* subject) {
    TOTAL++;
    printf(CYN "%d" RESET"." YEL " %s" RESET ":" RESET, TOTAL, subject);
    if (expression) { 
    	printf(GRN " %s\n" RESET, PASS);    
        SUCCESS++;
    }
    else{
    	printf(RED " %s\n" RESET, FAIL);    
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
    printf("Total coverage: %.2f%%\n", coverage());
    return TOTAL - SUCCESS;
}

