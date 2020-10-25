#ifndef SMARTPOINTERS_UNIQUE_PTR_H
#define SMARTPOINTERS_UNIQUE_PTR_H


#include <iostream>

class UnCopyAble {
protected:
    UnCopyAble() {}
    ~UnCopyAble() {}

private:
    UnCopyAble(const UnCopyAble&);
    UnCopyAble& operator=(const UnCopyAble&);
};

template <class T>
class UniquePtr: private UnCopyAble{
public:
    explicit UniquePtr(T* ptr);
    ~UniquePtr();

    T* get() const;
    T operator*()const ;
    T* operator->()const ;

private:
    T* m_ptr;

    friend class TestSafePtr;
};


#include "unique_ptr.hpp"


#endif //SMARTPOINTERS_UNIQUE_PTR_H
