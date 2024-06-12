#ifndef UNIQUE_PTR
#define UNIQUE_PTR

template<typename T>
class UniquePtr {

public:
    UniquePtr();
    UniquePtr(T* ptr);
    ~UniquePtr();
    UniquePtr(UniquePtr&) = delete; // copy constructor
    UniquePtr& operator=(UniquePtr&) = delete; 
    T* get();
    T& operator*();
    T* operator->();
    void reset();
    void reset(T* ptr);
    explicit operator bool();
    T* release();

private:
    T* _p;
};

template<typename T, typename... Args>
UniquePtr<T> make_unique(Args&&... args) {
    return UniquePtr<T>(new T(std::forward<Args>(args)...));
}






#include "unique_ptr.hpp"

#endif //UNIQUE_PTR