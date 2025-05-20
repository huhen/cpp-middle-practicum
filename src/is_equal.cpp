#include "is_equal.h"

#include <cstdlib>

bool is_equal(double a, double b, double epsilon) { return std::abs(a - b) < epsilon; }

bool is_equal(double a, double b) { return is_equal(a, b, 1e-7); }

bool is_equal(float a, double b) { return is_equal(static_cast<double>(a), b, 1e-5); }
bool is_equal(double a, float b) { return is_equal(a, static_cast<double>(b), 1e-5); }
bool is_equal(float a, float b) { return is_equal(static_cast<double>(a), static_cast<double>(b), 1e-5); }