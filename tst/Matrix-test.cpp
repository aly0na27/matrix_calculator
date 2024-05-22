#include "gtest/gtest.h"
#include "Matrix.h"


TEST(MatrixCalculatorTest, AdditionTest) {
    std::vector<std::vector<double>> input1 = {{1, 2}, {3, 4}};
    std::vector<std::vector<double>> input2 = {{5, 6}, {7, 8}};

    std::vector<std::vector<double>> input3 = {{1.3, -7.923}, {3.8, 4.12}};
    std::vector<std::vector<double>> input4 = {{5.26, 6.89}, {7.32, 8.98}};

    std::vector<std::vector<double>> input5 = {{1.3, -7.923}, {3.8, 4.12}};
    std::vector<std::vector<double>> input6 = {{5.26, 6.89}};

    std::vector<std::vector<double>> input7 = {{1.3, -7.923}, {3.8, 4.12}};
    std::vector<std::vector<double>> input8 = {};

    MatrixCalculator matrix1(input1);
    MatrixCalculator matrix2(input2);
    MatrixCalculator matrix3(input3);
    MatrixCalculator matrix4(input4);
    MatrixCalculator matrix5(input5);
    MatrixCalculator matrix6(input6);
    MatrixCalculator matrix7(input7);
    MatrixCalculator matrix8(input8);

    MatrixCalculator sum1 = matrix1 + matrix2;
    MatrixCalculator sum2 = matrix3 + matrix4;

    std::vector<std::vector<double>> expected1 = {{6, 8}, {10, 12}};
    std::vector<std::vector<double>> expected2 = {{6.56, -1.033}, {11.12, 13.1}};
    MatrixCalculator expectedSum1(expected1);
    MatrixCalculator expectedSum2(expected2);

    EXPECT_EQ(sum1, expectedSum1);
    EXPECT_EQ(sum2, expectedSum2);
    ASSERT_THROW(matrix5 + matrix6, std::runtime_error);
    ASSERT_THROW(matrix7 + matrix8, std::runtime_error);
}

TEST(MatrixCalculatorTest, SubstructionTest) {
    std::vector<std::vector<double>> input1 = {{1, 2}, {3, 4}};
    std::vector<std::vector<double>> input2 = {{5, 6}, {7, 8}};

    std::vector<std::vector<double>> input3 = {{1.3, -7.923}, {3.8, 4.12}};
    std::vector<std::vector<double>> input4 = {{5.26, 6.89}, {7.32, 8.98}};

    std::vector<std::vector<double>> input5 = {{1.3, -7.923}, {3.8, 4.12}};
    std::vector<std::vector<double>> input6 = {{5.26, 6.89}};

    std::vector<std::vector<double>> input7 = {{1.3, -7.923}, {3.8, 4.12}};
    std::vector<std::vector<double>> input8 = {};

    MatrixCalculator matrix1(input1);
    MatrixCalculator matrix2(input2);
    MatrixCalculator matrix3(input3);
    MatrixCalculator matrix4(input4);
    MatrixCalculator matrix5(input5);
    MatrixCalculator matrix6(input6);
    MatrixCalculator matrix7(input7);
    MatrixCalculator matrix8(input8);

    MatrixCalculator sum1 = matrix1 - matrix2;
    MatrixCalculator sum2 = matrix3 - matrix4;

    std::vector<std::vector<double>> expected1 = {{-4, -4}, {-4, -4}};
    std::vector<std::vector<double>> expected2 = {{-3.96, -14.813}, {-3.52, -4.86}};
    MatrixCalculator expectedSum1(expected1);
    MatrixCalculator expectedSum2(expected2);

    EXPECT_EQ(sum1, expectedSum1);
    EXPECT_EQ(sum2, expectedSum2);
    ASSERT_THROW(matrix5 + matrix6, std::runtime_error);
    ASSERT_THROW(matrix7 + matrix8, std::runtime_error);
}

TEST(MatrixCalculatorTest, MultiplyTest) {
    std::vector<std::vector<double>> input1 = {{1, 2}, {3, 4}};
    std::vector<std::vector<double>> input2 = {{5, 6}, {7, 8}};

    std::vector<std::vector<double>> input3 = {{1.3, -7.923}, {3.8, 4.12}};
    std::vector<std::vector<double>> input4 = {{5.26, 6.89}, {7.32, 8.98}};

    std::vector<std::vector<double>> input5 = {{1.3, -7.923}, {3.8, 4.12}, {9, 1.2}};
    std::vector<std::vector<double>> input6 = {{5.26, 6.89}, {7.32, 8.98}};

    std::vector<std::vector<double>> input7 = {{1, 2}, {3, 4}};
    std::vector<std::vector<double>> input8 = {{5, 6, 7}, {7, 8, 9}, {10, 11, 12}};

    std::vector<std::vector<double>> input9 = {{1, 2}, {3, 4}};
    std::vector<std::vector<double>> input10 = {{5, 6, 7}, {7, 8, 9}, {10, 11, 12}};

    std::vector<std::vector<double>> input11 = {};
    std::vector<std::vector<double>> input12 = {{5, 6, 7}, {7, 8, 9}, {10, 11, 12}};

    MatrixCalculator matrix1(input1);
    MatrixCalculator matrix2(input2);
    MatrixCalculator matrix3(input3);
    MatrixCalculator matrix4(input4);
    MatrixCalculator matrix5(input5);
    MatrixCalculator matrix6(input6);
    MatrixCalculator matrix7(input7);
    MatrixCalculator matrix8(input8);
    MatrixCalculator matrix9(input9);
    MatrixCalculator matrix10(input10);


    MatrixCalculator sum1 = matrix1 * matrix2;
    MatrixCalculator sum2 = matrix3 * matrix4;
    MatrixCalculator sum3 = matrix5 * matrix6;


    std::vector<std::vector<double>> expected1 = {{19, 22}, {43, 50}};
    std::vector<std::vector<double>> expected2 = {{-51.15836, -62.19154}, {50.1464, 63.1796}};
    std::vector<std::vector<double>> expected3 = {{-51.15836, -62.19154}, {50.1464,	63.1796}, {56.124, 72.786}};
    MatrixCalculator expectedSum1(expected1);
    MatrixCalculator expectedSum2(expected2);
    MatrixCalculator expectedSum3(expected3);

    EXPECT_EQ(sum1, expectedSum1);
    EXPECT_EQ(sum2, expectedSum2);
    EXPECT_EQ(sum3, expectedSum3);
    ASSERT_THROW(matrix7 * matrix8, std::runtime_error);
    ASSERT_THROW(matrix9 * matrix10, std::runtime_error);
}

TEST(MatrixCalculatorTest, DeterminantTest) {
    std::vector<std::vector<double>> input1 = {{1, 2}, {3, 4}};
    std::vector<std::vector<double>> input2 = {{1.8, 2.34, 24.9}, {0.56, 4.23, 21.4}, {1, 2, 3}};
    std::vector<std::vector<double>> input3 = {};
    std::vector<std::vector<double>> input4 = {{1.8, 2.34, 24.9}, {0.56, 4.23, 21.4}};
    std::vector<std::vector<double>> input5 = {{1.8}};

    MatrixCalculator matrix1(input1);
    MatrixCalculator matrix2(input2);
    MatrixCalculator matrix3(input3);
    MatrixCalculator matrix4(input4);
    MatrixCalculator matrix5(input5);

    double determinant1 = matrix1.determinant();
    double determinant2 = matrix2.determinant();
    double determinant5 = matrix5.determinant();

    double expected1 = -2;
    double expected2 = -85.4922;
    EXPECT_EQ(determinant1, expected1);
    EXPECT_EQ(determinant2, expected2);
    EXPECT_EQ(determinant5, 1.8);
    ASSERT_THROW(matrix3.determinant(), std::runtime_error);
    ASSERT_THROW(matrix4.determinant(), std::runtime_error);
}

TEST(MatrixCalculatorTest, TransposeTest) {
    std::vector<std::vector<double>> input1 = {{1, 2}, {3, 4}};
    std::vector<std::vector<double>> input2 = {{1.8, 2.34, 24.9}, {0.56, 4.23, 21.4}, {1, 2, 3}};
    std::vector<std::vector<double>> input3 = {};
    std::vector<std::vector<double>> input4 = {{1.8, 2.34, 24.9}, {0.56, 4.23, 21.4}};
    std::vector<std::vector<double>> input5 = {{1.8}};

    MatrixCalculator matrix1(input1);
    MatrixCalculator matrix2(input2);
    MatrixCalculator matrix3(input3);
    MatrixCalculator matrix4(input4);
    MatrixCalculator matrix5(input5);

    MatrixCalculator m1 = matrix1.transpose();
    MatrixCalculator m2 = matrix2.transpose();
    MatrixCalculator m3 = matrix3.transpose();
    MatrixCalculator m4 = matrix4.transpose();
    MatrixCalculator m5 = matrix5.transpose();

    std::vector<std::vector<double>> output1 = {{1, 3}, {2, 4}};
    std::vector<std::vector<double>> output2= {{1.8, 0.56, 1}, {2.34, 4.23, 2}, {24.9, 21.4, 3}};
    std::vector<std::vector<double>> output3  = {};
    std::vector<std::vector<double>> output4 = {{1.8, 0.56}, {2.34, 4.23}, {24.9, 21.4}};
    std::vector<std::vector<double>> output5 = {{1.8}};

    MatrixCalculator expected1(output1);
    MatrixCalculator expected2(output2);
    MatrixCalculator expected3(output3);
    MatrixCalculator expected4(output4);
    MatrixCalculator expected5(output5);

    EXPECT_EQ(matrix1, expected1);
    EXPECT_EQ(matrix2, expected2);
    EXPECT_EQ(matrix3, expected3);
    EXPECT_EQ(matrix4, expected4);
    EXPECT_EQ(matrix5, expected5);
}





