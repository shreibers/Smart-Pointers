

#include "safe_ptr.h"
#include "unique_ptr.h"
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
    if(safePtr2.m_ptr == ptr && !safePtr.m_ptr){
        std::cout<<"copy_ctor ok"<<std::endl;
    }
    else{
        std::cout<<"copy_ctor failed"<<std::endl;
    }

}

void TestSafePtr::test_assigment_operator() {

    SafePtr<int> safePtr(new int());
    SafePtr<int> safePtr2(new int());
    int* ptr = safePtr.m_ptr;
    safePtr2 = safePtr;
    if(safePtr2.m_ptr == ptr && !safePtr.m_ptr){
        std::cout<<"assigment_operator ok"<<std::endl;
    }
    else{
        std::cout<<"assigment_operator failed"<<std::endl;
    }
}

void TestSafePtr::test_operator_asterisk() {

    SafePtr<int> safePtr(new int(10));
    if(*safePtr == 10){
        std::cout<<"operator_asterisk ok"<<std::endl;
    }
    else{
        std::cout<<"operator_asterisk failed"<<std::endl;
    }
}

void TestSafePtr::test_operator_arrow() {

    testPtr* ptr = new testPtr;
    ptr->num = 10;
    SafePtr<testPtr> sp(ptr);
    if(sp->num == 10){
        std::cout<<"operator_arrow ok"<<std::endl;
    }
    else{
        std::cout<<"operator_arrow failed"<<std::endl;
    }
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
    if(*uniquePtr == 10){
        std::cout<<"operator_asterisk ok"<<std::endl;
    }
    else{
        std::cout<<"operator_asterisk failed"<<std::endl;
    }
}

void TestUniquePtr::test_operator_arrow(){
    testPtr* ptr = new testPtr;
    ptr->num = 10;
    UniquePtr<testPtr> up(ptr);
    if(up->num == 10){
        std::cout<<"operator_arrow ok"<<std::endl << std::endl;
    }
    else{
        std::cout<<"operator_arrow failed"<<std::endl << std::endl;
    }
}
