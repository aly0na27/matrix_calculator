#pragma once

#include <iostream>
#include <vector>

class MatrixCalculator {
private:
    std::vector<std::vector<double>> data;

    double determinantHelper(const std::vector<std::vector<double>> &mat) {
        int n = mat.size();
        if (n == 2) {
            return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
        }

        double det = 0;
        for (int i = 0; i < n; ++i) {
            std::vector<std::vector<double>> submatrix(n - 1, std::vector<double>(n - 1, 0.0));
            for (int j = 1; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (k < i) {
                        submatrix[j - 1][k] = mat[j][k];
                    } else if (k > i) {
                        submatrix[j - 1][k - 1] = mat[j][k];
                    }
                }
            }
            int sign = (i % 2 == 0) ? 1 : -1;
            det += sign * mat[0][i] * determinantHelper(submatrix);
        }

        return det;
    }

    void getCofactor(const std::vector<std::vector<double>> &mat, std::vector<std::vector<double>> &temp, int p, int q,
                     int n) {
        int i = 0, j = 0;
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                if (row != p && col != q) {
                    temp[i][j++] = mat[row][col];
                    if (j == n - 1) {
                        j = 0;
                        i++;
                    }
                }
            }
        }
    }

public:
    MatrixCalculator(const std::vector<std::vector<double>> &input) : data(input) {}

    MatrixCalculator operator+(const MatrixCalculator &other) const;

    MatrixCalculator operator*(const MatrixCalculator &other) const;

    MatrixCalculator operator-(const MatrixCalculator &other) const;

    MatrixCalculator operator/( MatrixCalculator &other) const;

    bool operator==(const MatrixCalculator &other) const;

    MatrixCalculator pow(int power);

    double determinant();

    MatrixCalculator transpose();

    int rank();

    MatrixCalculator inverse();

    void print() const;

};
