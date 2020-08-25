
#ifndef SMARTPOINTERS_TEST_H
#define SMARTPOINTERS_TEST_H


class TestSafePtr{
public:
    void test_copy_ctor();
    void test_assigment_operator();
    void test_operator_asterisk();
    void test_operator_arrow();

};

class TestUniquePtr{
public:
    void test_copy_ctor();
    void test_assigment_operator();
    void test_operator_asterisk();
    void test_operator_arrow();
};

class TestSharedPtr{
public:
    void test_copy_ctor();
    void test_assigment_operator();
    void test_operator_asterisk();
    void test_operator_arrow();

};


#endif //SMARTPOINTERS_TEST_H
