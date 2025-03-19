#pragma once
#include <vector>

constexpr uint8_t dynamic = 0x1;

template<class T> 
class Matrix {
public:
    Matrix(size_t rows, size_t cols);
    Matrix& operator=(const Matrix<T>&);
    Matrix& operator=(const std::initializer_list<T>);

    // Matrix Addition
    Matrix operator+(const Matrix);
    // Scalar Addition
    Matrix operator+(const T);

    // Matrix Subtraction
    Matrix operator-(const Matrix);
    // Scalar Subtraction
    Matrix operator-(const T);

    // Matrix Multiplication
    Matrix operator*(const Matrix);
    // Scalar Multiplication
    Matrix operator*(const T);

    // Scalar Division
    Matrix operator/(const T);

    Matrix inverse();
    Matrix transpose();

    T& operator()(size_t row, size_t col) const;

    void print();

    size_t rows();
    size_t cols();
    size_t size();
private:
    size_t m_rows, m_cols;
    T** m_matrix;

    void alloc();
};

#include "../src/mavec.tpp"