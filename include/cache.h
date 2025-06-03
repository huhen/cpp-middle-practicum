#include <unordered_map>

template <typename Derived>
class Cache {
public:
    template <typename T>
    auto &&compute(T input) {
        static std::unordered_map<size_t, decltype(static_cast<Derived *>(this)->Calculate(input))> cache;
        auto key = std::hash<T>{}(input);
        if (cache.find(key) == cache.end()) {
            cache[key] = static_cast<Derived *>(this)->Calculate(input);
        }
        return cache[key];
    }
};