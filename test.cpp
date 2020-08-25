

#include "safe_ptr.h"
#include "unique_ptr.h"
#include "shared_ptr.h"
#include "test.h"

typedef struct testPtr{
    int num;
}testPtr;

//Tests of SafePtr class
void TestSafePtr::test_copy_ctor() {
    std::cout << std::endl << "*****Test SafePtr class*****" << std::endl << std::endl ;

    SafePtr<int> safePtr(new int());
    int* ptr = safePtr.m_ptr;
    SafePtr<int> safePtr2 = safePtr;
    std::cout<< ((safePtr2.m_ptr == ptr && !safePtr.m_ptr) ? "copy_ctor ok" : "copy_ctor failed") << std::endl;

}

void TestSafePtr::test_assigment_operator() {

    SafePtr<int> safePtr(new int());
    SafePtr<int> safePtr2(new int());
    int* ptr = safePtr.m_ptr;
    safePtr2 = safePtr;

    std::cout<< ((safePtr2.m_ptr == ptr && !safePtr.m_ptr) ? "assigment_operator ok" : "assigment_operator failed") << std::endl;

}

void TestSafePtr::test_operator_asterisk() {

    SafePtr<int> safePtr(new int(10));
    std::cout<< ((*safePtr == 10) ? "operator_asterisk ok" : "operator_asterisk failed") << std::endl;

}

void TestSafePtr::test_operator_arrow() {

    testPtr* ptr = new testPtr;
    ptr->num = 10;
    SafePtr<testPtr> sp(ptr);
    std::cout<< ((sp->num == 10) ? "operator_arrow ok" : "operator_arrow failed") << std::endl;

}


//Tests of SafePtr class
void TestUniquePtr::test_copy_ctor(){
    std::cout << std::endl << std::endl << "*****Test uniquePtr class*****" << std::endl << std::endl;

    UniquePtr<int> uniquePtr(new int());
//    UniquePtr<int> uniquePtr2 = uniquePtr; -> compilation error
}

void TestUniquePtr::test_assigment_operator(){
    UniquePtr<int> uniquePtr1(new int(5));
    UniquePtr<int> uniquePtr2(new int(10));
    //uniquePtr2 = uniquePtr1; -> compilation error
}

void TestUniquePtr::test_operator_asterisk(){
    UniquePtr<int> uniquePtr(new int(10));
    std::cout<< ((*uniquePtr == 10) ? "operator_asterisk ok" : "operator_asterisk failed") << std::endl;
}

void TestUniquePtr::test_operator_arrow(){
    testPtr* ptr = new testPtr;
    ptr->num = 10;
    UniquePtr<testPtr> up(ptr);
    std::cout<< ((up->num == 10) ? "operator_arrow ok" : "operator_arrow failed") << std::endl;

}

//Tests of SharedPtr class
void TestSharedPtr::test_copy_ctor() {
    std::cout << std::endl << "*****Test SharedPtr class*****" << std::endl << std::endl ;

    SharedPtr<int> sharedPtr(new int());
    size_t count_m_ptr = *(sharedPtr.m_counter);

    SharedPtr<int> sharedPtr2 = sharedPtr;
    std::cout<< ((sharedPtr2.m_ptr == sharedPtr.m_ptr )&&
                         (*(sharedPtr2.m_counter) == *(sharedPtr.m_counter))&&(*(sharedPtr.m_counter) == (count_m_ptr + 1)) ?
    "copy_ctor ok" : "copy_ctor failed") << std::endl;

}

void TestSharedPtr::test_assigment_operator() {
    SharedPtr<int> sharedPtr(new int());
    SharedPtr<int> sharedPtr2(new int(5));
    size_t count_ptr1 = *(sharedPtr.m_counter);
//    size_t* temp_ptr = sharedPtr2.m_counter;

    sharedPtr2 = sharedPtr;

    std::cout<< (((sharedPtr2.m_ptr == sharedPtr.m_ptr) &&
    (*(sharedPtr2.m_counter) == *(sharedPtr.m_counter)) &&
    (*(sharedPtr2.m_counter) == (count_ptr1 + 1)))?
    "assigment_operator ok" : "assigment_operator failed") << std::endl;
}

void TestSharedPtr::test_operator_asterisk() {

    SharedPtr<int> sharedPtr(new int(10));
    std::cout << ((*sharedPtr == 10) ? "operator_asterisk ok" : "operator_asterisk failed") << std::endl;

}

void TestSharedPtr::test_operator_arrow() {

    testPtr* ptr = new testPtr;
    ptr->num = 10;
    SharedPtr<testPtr> sp(ptr);
    std::cout<< ((sp->num == 10) ? "operator_arrow ok" : "operator_arrow failed") << std::endl;

}