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
T SafePtr<T>::operator*() const {
    return *m_ptr;
}

template <class T>
T* SafePtr<T>::operator->() const {
    return m_ptr;
}
