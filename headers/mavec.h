#pragma once
#include <vector>

template<class T> 
class Matrix {
public:
    Matrix(size_t rows, size_t cols);
    Matrix& operator=(const Matrix<T>&);
    Matrix& operator=(const std::initializer_list<T>);

    Matrix operator+(const Matrix);
    Matrix operator+(const T);

    Matrix operator*(const Matrix);
    Matrix operator*(const T);

    T& operator()(size_t row, size_t col) const;

    void printSize();
    void printData();

    size_t rows();
    size_t cols();
private:
    size_t m_rows, m_cols;
    T** m_matrix;

    void alloc();
};

#include "../src/mavec.tpp"