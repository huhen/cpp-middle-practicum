#include <print>

#if defined __clang__ || __GNUC__
#define FUNCTION_SIGNATURE __PRETTY_FUNCTION__
#elif defined __FUNCSIG__
#define FUNCTION_SIGNATURE __FUNCSIG__
#endif
template <typename T>
void func(T param) {
    // на консоль выведется сигнатура функции вместе с подставленным параметром
    std::println(FUNCTION_SIGNATURE);
}

struct TwoDimentions {
    size_t rows = 3;
    size_t cols = 3;
};
struct ThreeDimentions {
    size_t rows = 3;
    size_t cols = 3;
    size_t hight = 3;
};

template <typename T, auto dims>
struct Matrix {
    static inline const auto rows = dims.rows;
    static inline const auto cols = dims.cols;
    T data[rows * cols]{};
    Matrix operator+(const Matrix &other) const {
        Matrix result;
        for (size_t i = 0; i < rows * cols; ++i)
            result.data[i] = data[i] + other.data[i];
        return result;
    }
};

int main() {
    Matrix<float, TwoDimentions{}> matrix;
    Matrix<float, ThreeDimentions{}> matrix1;
}