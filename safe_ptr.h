
#ifndef SMARTPOINTERS_SAFE_PTR_H
#define SMARTPOINTERS_SAFE_PTR_H

#include <iostream>

template <class T>
class SafePtr{
public:
    explicit SafePtr(T* ptr);
    ~SafePtr();
    SafePtr(SafePtr& other);
    SafePtr& operator=(SafePtr& other);
    T* get() const;
    T operator*();
    T* operator->();

private:
    T* m_ptr;

    friend class Test;
};


template <class T>
SafePtr<T>::SafePtr(T *ptr):m_ptr(ptr) {}

template <class T>
SafePtr<T>::~SafePtr() {
    delete m_ptr;
}

template <class T>
SafePtr<T>::SafePtr(SafePtr &other):m_ptr(other.m_ptr) {
    other.m_ptr = NULL;
}

template <class T>
SafePtr<T>& SafePtr<T>::operator=(SafePtr &other) {
    if(this == &other){
        return *this;
    }
    delete m_ptr;
    m_ptr = other.m_ptr;
    other.m_ptr = NULL;
}

template <class T>
T* SafePtr<T>::get() const {
    return m_ptr;
}

template <class T>
T SafePtr<T>::operator*() {
    return *m_ptr;
}

template <class T>
T* SafePtr<T>::operator->() {
    return m_ptr;
}


#endif //SMARTPOINTERS_SAFE_PTR_H
