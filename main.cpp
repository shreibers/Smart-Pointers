#include "test.h"


int main() {

    Test test;
    test.test_copy_ctor();
    test.test_assigment_operator();
    test.test_operator_asterisk();
    test.test_operator_arrow();

    return 0;
}