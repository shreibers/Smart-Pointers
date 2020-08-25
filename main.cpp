#include "test.h"


int main() {

    TestSafePtr testSafePtr;
    testSafePtr.test_copy_ctor();
    testSafePtr.test_assigment_operator();
    testSafePtr.test_operator_asterisk();
    testSafePtr.test_operator_arrow();

    TestUniquePtr testUniquePtr;
    testUniquePtr.test_copy_ctor();
    testUniquePtr.test_assigment_operator();
    testUniquePtr.test_operator_asterisk();
    testUniquePtr.test_operator_arrow();

    TestSharedPtr testSharedPtr;
    testSharedPtr.test_copy_ctor();
    testSharedPtr.test_assigment_operator();
    testSharedPtr.test_operator_asterisk();
    testSharedPtr.test_operator_arrow();

    return 0;
}