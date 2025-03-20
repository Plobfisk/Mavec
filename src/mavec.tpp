#include "../headers/mavec.h"
#include <iostream>
#include <random>
#include <cassert>

template<class T> 
Matrix<T>::Matrix() {

}

template<class T> 
Matrix<T>::Matrix(size_t rows, size_t cols) : m_rows(rows), m_cols(cols) {
    alloc();

    for (size_t i = 0; i < m_rows; i++) {
        for (size_t j = 0; j < m_cols; j++) {
            m_matrix[i][j] = 0;
        }
    }
}

template<class T> 
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& matrix) {
    if (this == &matrix) {
        return *this;
    }

    m_rows = matrix.m_rows;
    m_cols = matrix.m_cols;

    for (size_t row = 0; row < m_rows; row++) {
        for (size_t col = 0; col < m_cols; col++) {
            m_matrix[row][col] = matrix(row, col);
            
        }
    }

    return *this;
}

template<class T> 
Matrix<T>& Matrix<T>::operator=(const std::initializer_list<T> list) {
    if (list.size() != m_rows * m_cols) {
        std::cout << "error" << std::endl;
        exit(1);
    }

	size_t row = 0;
    size_t col = 0;
	for (T value : list) {
		m_matrix[row][col] = value;

        if (col < m_cols - 1) {
            col++;
        }
        else {
            row++;
            col = 0;
        }
	}

	return *this;
}

template<class T> 
Matrix<T>& Matrix<T>::operator=(const T val) {
    for (size_t row = 0; row < m_rows; row++) {
        for (size_t col = 0; col < m_cols; col++) {
            m_matrix[row][col] = val;
        }
    }

    return *this;
}

template<class T> 
Matrix<T> Matrix<T>::Random(const T LO, const T HI) {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_real_distribution<T> dist(LO, HI);

    for (int i = 0; i < m_rows; i++) {
	    for (int j = 0; j < m_cols; j++) {
            m_matrix[i][j] = dist(gen);
	    }
    }

    return *this;
}

template<class T> 
Matrix<T> Matrix<T>::operator+(const Matrix matrix) {
    Matrix temp(m_rows, m_cols);
    for (int i = 0; i < m_rows; i++) {
	    for (int j = 0; j < m_cols; j++) {
            temp.m_matrix[i][j] = m_matrix[i][j] + matrix.m_matrix[i][j];
	    }
    }
	
    return temp;
}

template<class T> 
Matrix<T> Matrix<T>::operator+(const T scalar) {
    Matrix temp(m_rows, m_cols);
    for (int i = 0; i < m_rows; i++) {
	    for (int j = 0; j < m_cols; j++) {
            temp.m_matrix[i][j] = m_matrix[i][j] + scalar;
	    }
    }
	
    return temp;
}

template<class T> 
Matrix<T> Matrix<T>::operator-(const Matrix matrix) {
    Matrix temp(m_rows, m_cols);
    for (int i = 0; i < m_rows; i++) {
	    for (int j = 0; j < m_cols; j++) {
            temp.m_matrix[i][j] = m_matrix[i][j] - matrix.m_matrix[i][j];
	    }
    }
	
    return temp;
}

template<class T> 
Matrix<T> Matrix<T>::operator-(const T scalar) {
    Matrix temp(m_rows, m_cols);
    for (int i = 0; i < m_rows; i++) {
	    for (int j = 0; j < m_cols; j++) {
            temp.m_matrix[i][j] = m_matrix[i][j] - scalar;
	    }
    }
	
    return temp;
}

template<class T> 
Matrix<T> Matrix<T>::operator*(const Matrix<T>& matrix) {
    T scalar = matrix(0,0);
    if (matrix.m_rows == 1 && matrix.m_cols == 1) {
        Matrix temp(m_rows, m_cols);
        for (int i = 0; i < m_rows; i++) {
	        for (int j = 0; j < m_cols; j++) {
                temp(j, i) = m_matrix[j][i] * scalar;
	        }
        }
        return temp;
    }
    else {
        Matrix<T> temp(m_rows, matrix.m_cols);
        for (size_t i = 0; i < m_rows; i++) {
            for (size_t k = 0; k < m_cols; k++) {
                T val = m_matrix[i][k];
                for (size_t j = 0; j < matrix.m_cols; j++) {
                    temp.m_matrix[i][j] += val * matrix.m_matrix[k][j];
                }
            }
        }
        return temp;
    }
}


template<class T> 
Matrix<T> Matrix<T>::operator*(const T scalar) {
    Matrix temp(m_rows, m_cols);
    for (int i = 0; i < m_rows; i++) {
	    for (int j = 0; j < m_cols; j++) {
            temp(j, i) = m_matrix[j][i] * scalar;
	    }
    }
	
    return temp;
}

template<class T> 
Matrix<T> Matrix<T>::operator/(const T scalar) {
    Matrix temp(m_rows, m_cols);
    for (int i = 0; i < m_rows; i++) {
	    for (int j = 0; j < m_cols; j++) {
            temp(j, i) = m_matrix[j][i] / scalar;
	    }
    }
	
    return temp;
}

template<class T> 
Matrix<T> Matrix<T>::inverse() {

}

template<class T> 
Matrix<T> Matrix<T>::transpose() {
    Matrix temp(m_cols, m_rows);

    for (int i = 0; i < m_cols; i++) {
	    for (int j = 0; j < m_rows; j++) {
            temp(j, i) = m_matrix[i][j];
	    }
    }

    return temp;
}

template<class T>
T& Matrix<T>::operator()(size_t row, size_t col) {
    if (row > m_rows || col > m_cols) assert("Error: Out of bounds");

    return m_matrix[row][col];
}

template<class T>
const T& Matrix<T>::operator()(size_t row, size_t col) const {
    if (row > m_rows || col > m_cols) assert("Error: Out of bounds");

    return m_matrix[row][col];
}

template<class T> 
void Matrix<T>::print() {
    std::cout << "Matrix: \n";
    for (size_t i = 0; i < m_rows; i++) {
        for (size_t j = 0; j < m_cols; j++) {
            std::cout << '['<< m_matrix[i][j] << ']';
        }
        std::cout << std::endl;
    }
}

template<class T> 
size_t Matrix<T>::rows() {
    return m_rows;
}

template<class T> 
size_t Matrix<T>::cols() {
    return m_cols;
}

template<class T> 
size_t Matrix<T>::size(int rows, int cols) {
    if (rows > -1 || cols > -1) {
        if (rows > -1) {
            m_rows = rows;
        }
        if (cols > -1) {
            m_cols = cols;
        }

        alloc();
    }

    return m_rows * m_cols;
}

template<class T> 
void Matrix<T>::alloc() {
    m_matrix = new T*[m_rows];
    for (size_t i = 0; i < m_rows; i++) {
        m_matrix[i] = new T[m_cols];
    }
}



template<class T>
Vector<T>::Vector() : Matrix<T>() {}

template<class T>
Vector<T>::Vector(size_t size) : Matrix<T>(size, 1) {}

template<class T>
T& Vector<T>::operator()(size_t index) {
    return Matrix<T>::operator()(index, 0);
}

template<class T>
const T& Vector<T>::operator()(size_t index) const {
    return Matrix<T>::operator()(index, 0);
}

template<class T>
size_t Vector<T>::size(int size) {
    return Matrix<T>::size(size, 1);
}



template<class T>
RowVector<T>::RowVector() : Matrix<T>() {}

template<class T>
RowVector<T>::RowVector(size_t size) : Matrix<T>(1, size) {}

template<class T>
T& RowVector<T>::operator()(size_t index) {
    return Matrix<T>::operator()(0, index);
}

template<class T>
const T& RowVector<T>::operator()(size_t index) const {
    return Matrix<T>::operator()(0, index);
}

template<class T>
size_t RowVector<T>::size(int size) {
    return Matrix<T>::size(1, size);
}