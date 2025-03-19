#include "../headers/mavec.h"

#include <iostream>

int main() {
    Matrix<double> matrix(3,3);

    matrix = {1,2,3,4,5,6,7,8,9};

    matrix.transpose().print();

    std::cout << matrix.size() << std::endl;

    return 0;
}