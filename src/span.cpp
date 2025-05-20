#include "span.h"
#include <iterator>
#include <memory>

template <typename T>
template <typename It>
Span<T>::Span(It first, size_type count) : data_{std::to_address(first)}, size_{count} {}

template <typename T>
template <typename It1, typename It2>
Span<T>::Span(It1 first, It2 last) : Span{first, std::distance(first, last)} {}

template <typename T>
Span<T>::reference Span<T>::operator[](size_type idx) {
    return data_[idx];
}

template <typename T>
Span<T>::const_reference Span<T>::operator[](size_type idx) const {
    return data_[idx];
}

template <typename T>
bool Span<T>::empty() const {
    return data_ == nullptr || size_ == 0;
}

template <typename T>
Span<T>::pointer Span<T>::data() {
    return data_;
}

template <typename T>
Span<T>::const_pointer Span<T>::data() const {
    return data_;
}

template <typename T>
Span<T>::size_type Span<T>::size() const {
    return size_;
}

template <typename T>
Span<const std::byte> as_bytes(Span<T> span) {
    Span<const std::byte> result{reinterpret_cast<const std::byte *>(span.data()), span.size() * sizeof(T)};
    return result;
}