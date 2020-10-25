template <class T>
UniquePtr<T>::UniquePtr(T *ptr):m_ptr(ptr){}

template <class T>
UniquePtr<T>::~UniquePtr() {
    delete m_ptr;
}

template <class T>
T* UniquePtr<T>::get() const {
    return m_ptr;
}

template <class T>
T UniquePtr<T>::operator*() const {
    return *m_ptr;
}

template <class T>
T* UniquePtr<T>::operator->() const {
    return m_ptr;
}
