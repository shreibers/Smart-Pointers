

#include "safe_ptr.h"
#include "test.h"

typedef struct testPtr{
    int num;

}testPtr;


void Test::test_copy_ctor() {

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

void Test::test_assigment_operator() {

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

void Test::test_operator_asterisk() {

    SafePtr<int> safePtr(new int(10));
    if(*safePtr == 10){
        std::cout<<"operator_asterisk ok"<<std::endl;
    }
    else{
        std::cout<<"operator_asterisk failed"<<std::endl;
    }
}

void Test::test_operator_arrow() {

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