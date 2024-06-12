#include "unique_ptr.h"

template<typename T>
UniquePtr<T>::UniquePtr() {
    _p = nullptr;
}

template<typename T>
UniquePtr<T>::~UniquePtr() {
    T* ptr = _p;
    delete ptr;
    _p = nullptr;
}

template<typename T>
UniquePtr<T>::UniquePtr(T* ptr) {
    _p = ptr;
}

template<typename T>
T* UniquePtr<T>::get() {
    return _p;
}

template<typename T>
T& UniquePtr<T>::operator*() {
    return *_p;
}

template<typename T>
T* UniquePtr<T>::operator->() {
    return _p;
}

template<typename T>
void UniquePtr<T>::reset() {
    _p = nullptr;
}

template<typename T>
void UniquePtr<T>::reset(T* ptr) {
    _p = ptr;
}

template<typename T>
UniquePtr<T>::operator bool() {
    return _p != nullptr;
}

template<typename T>
T* UniquePtr<T>::release() {
    T* result = _p;
    _p = nullptr;
    return result;
}