#include <memory>

template <typename T>
T error_value;

// Specialization for int:
template <>
int error_value<int> = -1;

// Specialization for pointers:
template <typename T>
T* error_value<T*> = nullptr;

// Specialization for unique_ptr:
template <typename T>
T* error_value<std::unique_ptr<T>> = nullptr;

// Specialization for unique_ptr:
template <typename T>
T* error_value<std::shared_ptr<T>> = nullptr; 
