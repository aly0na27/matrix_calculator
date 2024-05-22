#include <vector>
#include "Matrix.h"

MatrixCalculator MatrixCalculator::operator+(const MatrixCalculator &other) const {
    if (data.size() == 0 || other.data.size() == 0) {
        std::runtime_error("Матрица пустая");
    }
    if (data.size() != other.data.size() || data[0].size() != other.data.size()) {
        throw std::runtime_error("Размеры матриц не совпадают");
    }
    std::vector<std::vector<double>> result;
    for (size_t i = 0; i < data.size(); ++i) {
        std::vector<double> row;
        for (size_t j = 0; j < data[0].size(); ++j) {
            row.push_back(data[i][j] + other.data[i][j]);
        }
        result.push_back(row);
    }
    return MatrixCalculator(result);
}

MatrixCalculator MatrixCalculator::operator*(const MatrixCalculator &other) const {
    if (data.size() == 0 || other.data.size() == 0) {
        std::runtime_error("Матрица пустая");
    }
    if (data[0].size() != other.data.size()) {
        throw std::runtime_error("Длина строк 1 матрицы не совпадает с высотой 2 матрицы");
    }
    std::vector<std::vector<double>> result(data.size(), std::vector<double>(other.data[0].size(), 0));
    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = 0; j < other.data[0].size(); ++j) {
            for (size_t k = 0; k < data[0].size(); ++k) {
                result[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return MatrixCalculator(result);
}

MatrixCalculator MatrixCalculator::operator-(const MatrixCalculator &other) const {
    if (data.size() == 0 || other.data.size() == 0) {
        std::runtime_error("Матрица пустая");
    }
    if (data.size() != other.data.size() || data[0].size() != other.data.size()) {
        throw std::runtime_error("Размеры матриц не совпадают");
    }

    std::vector<std::vector<double>> result;
    for (size_t i = 0; i < data.size(); ++i) {
        std::vector<double> row;
        for (size_t j = 0; j < data[0].size(); ++j) {
            row.push_back(data[i][j] - other.data[i][j]);
        }
        result.push_back(row);
    }
    return MatrixCalculator(result);
}

MatrixCalculator MatrixCalculator::operator/( MatrixCalculator& other) const {
    if (data.size() == 0 || other.data.size() == 0) {
        throw std::runtime_error("Матрицы пустые");
    }

    if (other.data.size() != other.data[0].size()) {
        throw std::runtime_error("Вторая матрица не квадратная");
    }

    if (data[0].size() != other.data.size()) {
         throw std::runtime_error("Операция деления не выполнима");
    }

    MatrixCalculator inverse_other_matrix = other.inverse();
    MatrixCalculator matrix(data);
    return matrix * inverse_other_matrix;
}



bool MatrixCalculator::operator==(const MatrixCalculator &other) const {
    if (data.size() == 0 || other.data.size() == 0) {
        std::runtime_error("Матрица пустая");
    }
    if (data.size() != other.data.size() || data[0].size() != other.data[0].size()) {
        return false; // Размеры матриц не совпадают
    }

    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = 0; j < data[0].size(); ++j) {
            if (abs(data[i][j] - other.data[i][j]) >  0.00001) {
                return false; // Найдено несовпадение элементов
            }
        }
    }

    return true;
}

MatrixCalculator MatrixCalculator::pow(int power) {
    if (data.size() == 0) {
        throw std::runtime_error("Матрица пустая");
    }
    if (data.size() != data[0].size()) {
        throw std::runtime_error("Матрица не квадратная");
    }

    if (power == 0) {
        int n = data.size();
        std::vector<std::vector<double>> result(n, std::vector<double>(n, 0.0));
        for (int i = 0; i < n; ++i) {
            result[i][i] = 1.0;
        }
        MatrixCalculator res(result);
        return res;
    } else if (power == 1) {
        return data;
    } else {
        MatrixCalculator matrix(data);
        MatrixCalculator result = matrix.pow( power / 2);
        result = result * result;
        if (power % 2 == 1) {
            result = result * matrix;
        }
        return result;
    }

}

double MatrixCalculator::determinant() {
    if (data.size() == 0) {
        std::runtime_error("Матрица пустая");
    }

    if (data.size() != data[0].size()) {
        throw std::runtime_error("Матрица не квадратная");
    }

    if (data.size() == 1) {
        return data[0][0];
    }

    return determinantHelper(data);

}

MatrixCalculator MatrixCalculator::transpose() {
    if (data.size() == 0) {
        MatrixCalculator matrix(data);
        return matrix;
    }
    int rows = data.size();
    int cols = data[0].size();

    std::vector<std::vector<double>> transposed(cols, std::vector<double>(rows, 0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = data[i][j];
        }
    }

    return MatrixCalculator(transposed);

}

int MatrixCalculator::rank() {
    if (data.size() == 0) {
        throw std::runtime_error("Матрица пустая");
    }

    int rank = 0;
    int rows = data.size();
    int cols = data[0].size();

    std::vector<std::vector<double>> temp(data);

    for (int i = 0; i < cols; ++i) {
        if (rank == rows) {
            break;
        }

        if (temp[rank][i] == 0) {
            bool swapped = false;
            for (int j = rank + 1; j < rows; ++j) {
                if (temp[j][i] != 0) {
                    std::swap(temp[rank], temp[j]);
                    swapped = true;
                    break;
                }
            }

            if (!swapped) {
                continue;
            }
        }

        for (int j = 0; j < rows; ++j) {
            if (j != rank && temp[j][i] != 0) {
                int multiplier = temp[j][i] / temp[rank][i];
                for (int k = 0; k < cols; ++k) {
                    temp[j][k] -= multiplier * temp[rank][k];
                }
            }
        }

        rank++;
    }

    return rank;

}

MatrixCalculator MatrixCalculator::inverse() {
    int n = data.size();
    double det = determinant();
    if (det == 0) {
        throw std::runtime_error("Inverse does not exist as determinant is zero.");
    }
    std::vector<std::vector<double>> adjoint(n, std::vector<double>(n, 0.0));
    std::vector<std::vector<double>> inverseMatrix(n, std::vector<double>(n, 0.0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::vector<std::vector<double>> submatrix(n - 1, std::vector<double>(n - 1, 0.0));
            getCofactor(data, submatrix, i, j, n);
            MatrixCalculator submatrix_matrix(submatrix);
            adjoint[j][i] = (double )((i + j) % 2 == 0 ? 1.0 : -1.0) * submatrix_matrix.determinant();
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inverseMatrix[i][j] = adjoint[i][j] /det;
        }
    }

    return inverseMatrix;
}

void MatrixCalculator::print() const {
    for (const auto &row: data) {
        for (double elem: row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}

