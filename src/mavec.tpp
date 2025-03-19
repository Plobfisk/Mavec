#include "../headers/mavec.h"
#include <iostream>

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
Matrix<T>& Matrix<T>::operator=(const std::initializer_list<T> data) {
    if (data.size() != m_rows * m_cols) {
        std::cout << "error" << std::endl;
        exit(1);
    }

	size_t row = 0;
    size_t col = 0;
	for (T value : data) {
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
Matrix<T> Matrix<T>::operator*(const Matrix matrix) {
    Matrix temp(m_rows, matrix.m_cols);
    for (int i = 0; i < temp.m_rows; i++) {
	    for (int j = 0; j < temp.m_cols; j++) {
		    for (int k = 0; k < m_cols; k++) {
			    temp.m_matrix[i][j] += m_matrix[i][k] * matrix.m_matrix[k][j];
		    }
	    }
    }
	
    return temp;
}

template<class T> 
Matrix<T> Matrix<T>::operator*(const T scalar) {
    Matrix temp(m_rows, m_cols);
    for (int i = 0; i < m_rows; i++) {
	    for (int j = 0; j < m_cols; j++) {
            temp[j][i] = m_matrix[j][i] * scalar;
	    }
    }
	
    return temp;
}

template<class T> 
Matrix<T> Matrix<T>::operator/(const T scalar) {
    Matrix temp(m_rows, m_cols);
    for (int i = 0; i < m_rows; i++) {
	    for (int j = 0; j < m_cols; j++) {
            temp[j][i] = m_matrix[j][i] / scalar;
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
T& Matrix<T>::operator()(const size_t row, const size_t col) const {
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
size_t Matrix<T>::size() {
    return m_rows * m_cols;
}

template<class T> 
void Matrix<T>::alloc() {
    m_matrix = new T*[m_rows];
    for (size_t i = 0; i < m_rows; i++) {
        m_matrix[i] = new T[m_cols];
    }
}