#pragma once
#include <vector>


constexpr uint8_t dynamic = 0x1;

template<class T> 
class Matrix {
public:
    Matrix();
    Matrix(size_t, size_t);

    Matrix& operator=(const Matrix<T>&);
    Matrix& operator=(const std::initializer_list<T>);
    Matrix& operator=(const T);

    Matrix Random(const T, const T);

    // Matrix Addition
    Matrix operator+(const Matrix);
    // Scalar Addition
    Matrix operator+(const T);

    // Matrix Subtraction
    Matrix operator-(const Matrix);
    // Scalar Subtraction
    Matrix operator-(const T);

    // Matrix Multiplication
    Matrix operator*(const Matrix&);
    // Scalar Multiplication
    Matrix operator*(const T);

    // Scalar Division
    Matrix operator/(const T);

    Matrix inverse();
    Matrix transpose();

    T& operator()(size_t, size_t);
    const T& operator()(size_t, size_t) const;

    void print();

    size_t rows();
    size_t cols();
    size_t size(int rows = -1, int cols = -1);
private:
    size_t m_rows, m_cols;
    T** m_matrix;

    void alloc();
};

template<class T>
class Vector : public Matrix<T> {
public:
    Vector();
    Vector(size_t size);

    using Matrix<T>::operator=;

    T& operator()(size_t index);
    const T& operator()(size_t index) const;

    size_t size(int size = -1);
private:
    size_t m_rows, m_cols;
};

template<class T>
class RowVector : public Matrix<T> {
public:
    RowVector();
    RowVector(size_t size);

    using Matrix<T>::operator=;

    T& operator()(size_t index);
    const T& operator()(size_t index) const;

    size_t size(int size = -1);
};

#include "../src/mavec.tpp"