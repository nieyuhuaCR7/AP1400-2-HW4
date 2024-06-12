#include "shared_ptr.h"


// Default Constructor
template<typename T>
SharedPtr<T>::SharedPtr() {
    _p = nullptr;
    _use_count = new int(0);
}

template<typename T>
SharedPtr<T>::SharedPtr(T* ptr) {
    _p = ptr;
    _use_count = new int(1);
}

// Copy Constructor
template<typename T>
SharedPtr<T>::SharedPtr(SharedPtr<T>& other) {
    _p = other._p;
    _use_count = other._use_count;
    if (_p) {
        ++(*_use_count);
    }

}

// Destructor
template<typename T>
SharedPtr<T>::~SharedPtr() {
    if (_use_count) {
        *(_use_count) -= 1;
        if (*(_use_count) == 0) {
            // delete _use_count;
            delete _p;
            _p = nullptr;
            // _use_count = nullptr;
        }
    }
}

// Copy Assignment Constructor
template<typename T>
SharedPtr<T>& SharedPtr<T>::operator=(SharedPtr<T>& other) {
    if (this != &other) {
        _p = other._p;
        _use_count = other._use_count;
        if (_p) {
            ++(*_use_count);
        }
    }
    return *this;
}

// Dereference Operator
template<typename T>
T& SharedPtr<T>::operator*() {
    return *_p;
}

// Arrow Operator
template<typename T>
T* SharedPtr<T>::operator->() {
    return _p;
}

// Reset function
template<typename T>
void SharedPtr<T>::reset() {
    _p = nullptr;
    *(_use_count) = 0;
}

// Reset with a ptr
template<typename T>
void SharedPtr<T>::reset(T* ptr) {
    _p = ptr;
    *(_use_count) = 1;
}

// bool
template<typename T>
SharedPtr<T>::operator bool() {
    return _p != nullptr;
}

// use count
template<typename T>
int SharedPtr<T>::use_count() {
    return *_use_count;
}

template<typename T>
T* SharedPtr<T>::get() {
    return _p;
}