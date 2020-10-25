
#ifndef SMARTPOINTERS_SAFE_PTR_H
#define SMARTPOINTERS_SAFE_PTR_H

#include <iostream>

template <class T>
class SafePtr{
public:
    explicit SafePtr(T* ptr = NULL);
    ~SafePtr();
    SafePtr(SafePtr& other);

    SafePtr& operator=(SafePtr& other);
    T* get() const;

    T operator*()const ;
    T* operator->()const ;

private:
    T* m_ptr;

    friend class TestSafePtr;
};

#include safe_ptr.hpp



#endif //SMARTPOINTERS_SAFE_PTR_H
