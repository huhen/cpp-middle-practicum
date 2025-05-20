#pragma once

#include <cstddef>

template <typename T>
class Span {
public:
    /* определите зависимые типы reference, const_reference, pointer, const_pointer, size_type здесь */
    using reference = T &;
    using const_reference = const T &;
    using pointer = T *;
    using const_pointer = const T *;
    using size_type = size_t;

    template <typename It>
    Span(It first, size_type count);

    template <typename It1, typename It2>
    Span(It1 first, It2 last);

    reference operator[](size_type idx);
    const_reference operator[](size_type idx) const;

    bool empty() const;

    pointer data();
    const_pointer data() const;

    size_type size() const;

    Span subspan(size_type offset, size_type count) { return Span{data_ + offset, count}; }

private:
    pointer data_;
    size_type size_;
};

template <typename T>
Span<const std::byte> as_bytes(Span<T> span);