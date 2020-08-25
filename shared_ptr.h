

#ifndef SMARTPOINTERS_SHARED_PTR_H
#define SMARTPOINTERS_SHARED_PTR_H


#include <iostream>

template <class T>
class SharedPtr {
public:
    explicit SharedPtr(T* ptr = NULL);
    ~SharedPtr();
    SharedPtr(SharedPtr& other);

    T* get_ptr() const;

    SharedPtr& operator=(SharedPtr& other);
    explicit operator bool() const;

    T operator*()const ;
    T* operator->()const ;

private:
    T* m_ptr;
    size_t* m_counter;

    void delete_ptr();

    friend class TestSharedPtr;
};

#include "shared_ptr.hpp"
#endif //SMARTPOINTERS_SHARED_PTR_H
