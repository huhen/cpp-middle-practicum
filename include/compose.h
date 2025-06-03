#include <utility>

template <typename F, typename G>
class Compose {
    F f;
    G g;

public:
    template <typename F1, typename G1>
    Compose(F1 &&f, G1 &&g) : f(std::forward<F1>(f)), g(std::forward<G1>(g)) {}

    template <typename T>
    auto operator()(T &&x) const -> decltype(f(g(std::forward<T>(x)))) {
        return f(g(std::forward<T>(x)));
    }
};

template <typename F, typename G>
Compose<F, G> compose(F &&f, G &&g) {
    return Compose<F, G>(std::forward<F>(f), std::forward<G>(g));
}