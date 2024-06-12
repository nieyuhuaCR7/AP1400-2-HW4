#ifndef SHARED_PTR
#define SHARED_PTR

template<typename T>
class SharedPtr {

public:
  SharedPtr();
  SharedPtr(T* ptr);
  ~SharedPtr();
  T* get();
  SharedPtr(SharedPtr& other); // Copy Constructor
  SharedPtr& operator=(SharedPtr& other); // Copy Assignment Constructor
  T& operator*(); // dereference operator
  T* operator->(); // Arrow operator
  void reset(); // reset function
  void reset(T* ptr); // reset with parameter
  explicit operator bool(); // bool
  int use_count(); 

private:
  T* _p;
  int* _use_count;

};

template<typename T, typename... Args>
SharedPtr<T> make_shared(Args&&... args) {
    return SharedPtr<T>(new T(std::forward<Args>(args)...));
}

#include "shared_ptr.hpp"
#endif //SHARED_PTR