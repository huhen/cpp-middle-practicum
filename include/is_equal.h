#pragma once

template <typename T1, typename T2>
bool is_equal(const T1 &a, const T2 &b) {
    return a == b;
}

template <typename T1, typename T2>
bool is_equal(T1 *a, T2 *b) {
    return *a == *b;
}

bool is_equal(double a, double b, double epsilon);

bool is_equal(double a, double b);

bool is_equal(float a, double b);
bool is_equal(double a, float b);
bool is_equal(float a, float b);
