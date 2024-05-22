#include <iostream>
#include "Matrix.h"
//#include <vector>

int main() {
    MatrixCalculator matrix1({ {1.7, 2}, {3, 4}});
    MatrixCalculator matrix2({ {5, 6}, {7, 8}});
    MatrixCalculator matrix3({{4, 0, 2, 0}, {1, 3, -1, 2}, {0, 1, 0, 5}, {2, 4, 3, 1}});


    std::cout << "Addition of matrices:" << std::endl;
    auto additionResult = matrix1 + matrix2;
    additionResult.print();

    std::cout << "Subtraction of matrices:" << std::endl;
    auto subtractionResult = matrix1 - matrix2;

    std::cout << "Multiplication of matrices:" << std::endl;
    auto multiplicationResult = matrix1 * matrix2;
    multiplicationResult.print();

    std::cout << matrix1.determinant() << std::endl;
    matrix1.inverse().print();

    matrix1.pow(4).print();
    matrix1.pow(5).print();
    return 0;
}
