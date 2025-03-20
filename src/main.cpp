#include "../headers/mavec.h"

#include <iostream>

class Layer {

};

int main() {
    size_t N = 3;
    Vector<double> A(N);
    RowVector<double> B(N);
    A.Random(0,1);
    B.Random(0,1);

    Matrix<double> C(N,N);
    C.Random(0, 1);

    C.print();
    (B*A).print();
    (C* (B*A)).print();

    return 0;
}