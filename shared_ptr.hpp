
template <class T>
SharedPtr<T>::SharedPtr(T* ptr):m_ptr(ptr), m_counter(new size_t(1)){}

template <class T>
SharedPtr<T>::~SharedPtr(){
    delete_ptr();
}

template <class T>
template <class U>
SharedPtr<T>::SharedPtr(SharedPtr<U>& other):m_ptr(other.m_ptr), m_counter(other.m_counter){
    ++(*m_counter);
}

template <class T>
T* SharedPtr<T>::get_ptr() const{
    return m_ptr;
}

template <class T>
template <class U>
SharedPtr<T>& SharedPtr<T>::operator=(SharedPtr<U>& other){
    if(this->m_ptr == other.m_ptr){
        return *this;
    }

    delete_ptr();
    m_ptr = other.m_ptr;
    m_counter = other.m_counter;
    ++(*m_counter);
    return *this;
}

template <class T>
SharedPtr<T>::operator bool() const{
    return m_ptr != NULL;
}

template <class T>
T SharedPtr<T>::operator*() const {
    return *m_ptr;
}

template <class T>
T* SharedPtr<T>::operator->() const {
    return m_ptr;
}

template <class T>
void SharedPtr<T>::delete_ptr(){
    --(*m_counter);

    if(*m_counter == 0){
        delete m_counter;
        m_counter = NULL;

        delete m_ptr;
        m_ptr = NULL;
    }
}