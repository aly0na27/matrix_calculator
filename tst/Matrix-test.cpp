#include "gtest/gtest.h"
#include "Matrix.h"


TEST(MatrixCalculatorTest, AdditionTest) {
    std::vector<std::vector<double>> input1 = {{1, 2},
                                               {3, 4}};
    std::vector<std::vector<double>> input2 = {{5, 6},
                                               {7, 8}};

    std::vector<std::vector<double>> input3 = {{1.3, -7.923},
                                               {3.8, 4.12}};
    std::vector<std::vector<double>> input4 = {{5.26, 6.89},
                                               {7.32, 8.98}};

    std::vector<std::vector<double>> input5 = {{1.3, -7.923},
                                               {3.8, 4.12}};
    std::vector<std::vector<double>> input6 = {{5.26, 6.89}};

    std::vector<std::vector<double>> input7 = {{1.3, -7.923},
                                               {3.8, 4.12}};
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

    std::vector<std::vector<double>> expected1 = {{6,  8},
                                                  {10, 12}};
    std::vector<std::vector<double>> expected2 = {{6.56,  -1.033},
                                                  {11.12, 13.1}};
    MatrixCalculator expectedSum1(expected1);
    MatrixCalculator expectedSum2(expected2);

    EXPECT_EQ(sum1, expectedSum1);
    EXPECT_EQ(sum2, expectedSum2);
    ASSERT_THROW(matrix5 + matrix6, std::runtime_error);
    ASSERT_THROW(matrix7 + matrix8, std::runtime_error);
}

TEST(MatrixCalculatorTest, SubstructionTest) {
    std::vector<std::vector<double>> input1 = {{1, 2},
                                               {3, 4}};
    std::vector<std::vector<double>> input2 = {{5, 6},
                                               {7, 8}};

    std::vector<std::vector<double>> input3 = {{1.3, -7.923},
                                               {3.8, 4.12}};
    std::vector<std::vector<double>> input4 = {{5.26, 6.89},
                                               {7.32, 8.98}};

    std::vector<std::vector<double>> input5 = {{1.3, -7.923},
                                               {3.8, 4.12}};
    std::vector<std::vector<double>> input6 = {{5.26, 6.89}};

    std::vector<std::vector<double>> input7 = {{1.3, -7.923},
                                               {3.8, 4.12}};
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

    std::vector<std::vector<double>> expected1 = {{-4, -4},
                                                  {-4, -4}};
    std::vector<std::vector<double>> expected2 = {{-3.96, -14.813},
                                                  {-3.52, -4.86}};
    MatrixCalculator expectedSum1(expected1);
    MatrixCalculator expectedSum2(expected2);

    EXPECT_EQ(sum1, expectedSum1);
    EXPECT_EQ(sum2, expectedSum2);
    ASSERT_THROW(matrix5 + matrix6, std::runtime_error);
    ASSERT_THROW(matrix7 + matrix8, std::runtime_error);
}

TEST(MatrixCalculatorTest, MultiplyTest) {
    std::vector<std::vector<double>> input1 = {{1, 2},
                                               {3, 4}};
    std::vector<std::vector<double>> input2 = {{5, 6},
                                               {7, 8}};

    std::vector<std::vector<double>> input3 = {{1.3, -7.923},
                                               {3.8, 4.12}};
    std::vector<std::vector<double>> input4 = {{5.26, 6.89},
                                               {7.32, 8.98}};

    std::vector<std::vector<double>> input5 = {{1.3, -7.923},
                                               {3.8, 4.12},
                                               {9,   1.2}};
    std::vector<std::vector<double>> input6 = {{5.26, 6.89},
                                               {7.32, 8.98}};

    std::vector<std::vector<double>> input7 = {{1, 2},
                                               {3, 4}};
    std::vector<std::vector<double>> input8 = {{5,  6,  7},
                                               {7,  8,  9},
                                               {10, 11, 12}};

    std::vector<std::vector<double>> input9 = {{1, 2},
                                               {3, 4}};
    std::vector<std::vector<double>> input10 = {{5,  6,  7},
                                                {7,  8,  9},
                                                {10, 11, 12}};

    std::vector<std::vector<double>> input11 = {};
    std::vector<std::vector<double>> input12 = {{5,  6,  7},
                                                {7,  8,  9},
                                                {10, 11, 12}};

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


    std::vector<std::vector<double>> expected1 = {{19, 22},
                                                  {43, 50}};
    std::vector<std::vector<double>> expected2 = {{-51.15836, -62.19154},
                                                  {50.1464,   63.1796}};
    std::vector<std::vector<double>> expected3 = {{-51.15836, -62.19154},
                                                  {50.1464,   63.1796},
                                                  {56.124,    72.786}};
    MatrixCalculator expectedSum1(expected1);
    MatrixCalculator expectedSum2(expected2);
    MatrixCalculator expectedSum3(expected3);

    EXPECT_EQ(sum1, expectedSum1);
    EXPECT_EQ(sum2, expectedSum2);
    EXPECT_EQ(sum3, expectedSum3);
    ASSERT_THROW(matrix7 * matrix8, std::runtime_error);
    ASSERT_THROW(matrix9 * matrix10, std::runtime_error);
}

TEST(MatrixCalculatorTest, DivisionTest) {
    std::vector<std::vector<double>> input1 = {{1, 2},
                                               {3, 4}};
    std::vector<std::vector<double>> input2 = {{5, 6},
                                               {7, 8}};

    std::vector<std::vector<double>> input3 = {{1.3, -7.923},
                                               {3.8, 4.12}};
    std::vector<std::vector<double>> input4 = {{5.26, 6.89},
                                               {7.32, 8.98}};

    std::vector<std::vector<double>> input5 = {{1.3, -7.923},
                                               {3.8, 4.12},
                                               {9,   1.2}};
    std::vector<std::vector<double>> input6 = {{5.26, 6.89},
                                               {7.32, 8.98}};

    std::vector<std::vector<double>> input7 = {{1, 2},
                                               {3, 4}};
    std::vector<std::vector<double>> input8 = {{5,  6,  7},
                                               {7,  8,  9},
                                               {10, 11, 12}};

    std::vector<std::vector<double>> input9 = {{1, 2},
                                               {3, 4}};
    std::vector<std::vector<double>> input10 = {{5,  6,  7},
                                                {7,  8,  9},
                                                {10, 11, 12}};

    std::vector<std::vector<double>> input11 = {};
    std::vector<std::vector<double>> input12 = {{5,  6,  7},
                                                {7,  8,  9},
                                                {10, 11, 12}};

    std::vector<std::vector<double>> input13 = {{5,  6,  7},
                                                {7,  8,  9},
                                                {10, 11, 12}};
    std::vector<std::vector<double>> input14 = {{5,  6,  7},
                                                {7,  8,  9},
                                                {0,0,0}};

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
    MatrixCalculator matrix11(input11);
    MatrixCalculator matrix12(input12);
    MatrixCalculator matrix13(input13);
    MatrixCalculator matrix14(input14);


    MatrixCalculator sum1 = matrix1 / matrix2;
    MatrixCalculator sum2 = matrix3 / matrix4;
    MatrixCalculator sum3 = matrix5 / matrix6;


    std::vector<std::vector<double>> expected1 = {{3, -2},
                                                  {2, -1}};
    std::vector<std::vector<double>> expected2 = {{-21.771987, 15.82249},
                                                  {-1.23925,   1.40962}};
    std::vector<std::vector<double>> expected3 = {{-21.771987, 15.82249},
                                                  {-1.23925,   1.40962},
                                                  {-22.51125,  17.405625}};
    MatrixCalculator expectedSum1(expected1);
    MatrixCalculator expectedSum2(expected2);
    MatrixCalculator expectedSum3(expected3);

    EXPECT_EQ(sum1, expectedSum1);
    EXPECT_EQ(sum2, expectedSum2);
    EXPECT_EQ(sum3, expectedSum3);
    ASSERT_THROW(matrix7 / matrix8, std::runtime_error);
    ASSERT_THROW(matrix9 / matrix10, std::runtime_error);
    ASSERT_THROW(matrix11 / matrix12, std::runtime_error);
    ASSERT_THROW(matrix13 / matrix14, std::runtime_error);
}

TEST(MatrixCalculatorTest, EqualTest) {
    std::vector<std::vector<double>> input1 = {{1, 2},
                                               {3, 4}};
    std::vector<std::vector<double>> input2 = {{1, 2},
                                               {3, 4}};

    std::vector<std::vector<double>> input3 = {{1.3, -7.923},
                                               {3.8, 4.12}};
    std::vector<std::vector<double>> input4 = {{1.3, -7.923},
                                               {3.8, 4.123}};

    std::vector<std::vector<double>> input5 = {{1.3, -7.923},
                                               {3.8, 4.12},
                                               {9,   1.2}};
    std::vector<std::vector<double>> input6 = {{5.26, 6.89},
                                               {7.32, 8.98}};

    std::vector<std::vector<double>> input7 = {{1, 2},
                                               {3, 4}};
    std::vector<std::vector<double>> input8 = {{5,  6,  7},
                                               {7,  8,  9},
                                               {10, 11, 12}};

    std::vector<std::vector<double>> input9 = {{5,  6,  7},
                                               {7,  8,  9},
                                               {10, 11, 12}};;
    std::vector<std::vector<double>> input10 = {{5,  6,  7},
                                                {7,  8,  9},
                                                {10, 11, 12}};

    std::vector<std::vector<double>> input11 = {};
    std::vector<std::vector<double>> input12 = {{5,  6,  7},
                                                {7,  8,  9},
                                                {10, 11, 12}};

    std::vector<std::vector<double>> input13 = {{5,  6,  7},
                                                {7,  8,  9},
                                                {10, 11, 12}};
    std::vector<std::vector<double>> input14 = {{5,  6,  7},
                                                {7,  8,  9},
                                                {10, 11, 12.0007}};

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
    MatrixCalculator matrix11(input11);
    MatrixCalculator matrix12(input12);
    MatrixCalculator matrix13(input13);
    MatrixCalculator matrix14(input14);


    MatrixCalculator sum1 = matrix1 / matrix2;
    MatrixCalculator sum2 = matrix3 / matrix4;
    MatrixCalculator sum3 = matrix5 / matrix6;


    std::vector<std::vector<double>> expected1 = {{3, -2},
                                                  {2, -1}};
    std::vector<std::vector<double>> expected2 = {{-21.771987, 15.82249},
                                                  {-1.23925,   1.40962}};
    std::vector<std::vector<double>> expected3 = {{-21.771987, 15.82249},
                                                  {-1.23925,   1.40962},
                                                  {-22.51125,  17.405625}};
    MatrixCalculator expectedSum1(expected1);
    MatrixCalculator expectedSum2(expected2);
    MatrixCalculator expectedSum3(expected3);

    EXPECT_EQ(matrix1 == matrix2, true);
    EXPECT_EQ(matrix3 == matrix4, false);
    EXPECT_EQ(matrix5 == matrix6, false);
    EXPECT_EQ(matrix7 == matrix8, false);
    EXPECT_EQ(matrix9 == matrix10, true);
    EXPECT_EQ(matrix13 == matrix14, false);
    ASSERT_THROW(matrix11 == matrix12, std::runtime_error);
}

TEST(MatrixCalculatorTest, DeterminantTest) {
    std::vector<std::vector<double>> input1 = {{1, 2},
                                               {3, 4}};
    std::vector<std::vector<double>> input2 = {{1.8,  2.34, 24.9},
                                               {0.56, 4.23, 21.4},
                                               {1,    2,    3}};
    std::vector<std::vector<double>> input3 = {};
    std::vector<std::vector<double>> input4 = {{1.8,  2.34, 24.9},
                                               {0.56, 4.23, 21.4}};
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
    std::vector<std::vector<double>> input1 = {{1, 2},
                                               {3, 4}};
    std::vector<std::vector<double>> input2 = {{1.8,  2.34, 24.9},
                                               {0.56, 4.23, 21.4},
                                               {1,    2,    3}};
    std::vector<std::vector<double>> input3 = {};
    std::vector<std::vector<double>> input4 = {{1.8,  2.34, 24.9},
                                               {0.56, 4.23, 21.4}};
    std::vector<std::vector<double>> input5 = {{1.8}};

    MatrixCalculator matrix1(input1);
    MatrixCalculator matrix2(input2);
    MatrixCalculator matrix3(input3);
    MatrixCalculator matrix4(input4);
    MatrixCalculator matrix5(input5);

    MatrixCalculator m1 = matrix1.transpose();
    MatrixCalculator m2 = matrix2.transpose();
    MatrixCalculator m4 = matrix4.transpose();
    MatrixCalculator m5 = matrix5.transpose();

    std::vector<std::vector<double>> output1 = {{1, 3},
                                                {2, 4}};
    std::vector<std::vector<double>> output2 = {{1.8,  0.56, 1},
                                                {2.34, 4.23, 2},
                                                {24.9, 21.4, 3}};
    std::vector<std::vector<double>> output4 = {{1.8,  0.56},
                                                {2.34, 4.23},
                                                {24.9, 21.4}};
    std::vector<std::vector<double>> output5 = {{1.8}};

    MatrixCalculator expected1(output1);
    MatrixCalculator expected2(output2);
    MatrixCalculator expected4(output4);
    MatrixCalculator expected5(output5);

    EXPECT_EQ(m1, expected1);
    EXPECT_EQ(m2, expected2);
    ASSERT_THROW(matrix3.transpose(), std::runtime_error);
    EXPECT_EQ(m4, expected4);
    EXPECT_EQ(m5, expected5);
}

TEST(MatrixCalculatorTest, RankTest) {
    std::vector<std::vector<double>> input1 = {{1, 2},
                                               {3, 4}};
    std::vector<std::vector<double>> input2 = {{1.8,  2.34, 24.9},
                                               {0.56, 4.23, 21.4},
                                               {1,    2,    3}};
    std::vector<std::vector<double>> input3 = {};
    std::vector<std::vector<double>> input4 = {{1.8,  2.34, 24.9},
                                               {0.56, 4.23, 21.4}};
    std::vector<std::vector<double>> input5 = {{1.8}};

    MatrixCalculator matrix1(input1);
    MatrixCalculator matrix2(input2);
    MatrixCalculator matrix3(input3);
    MatrixCalculator matrix4(input4);
    MatrixCalculator matrix5(input5);

    int determinant1 = matrix1.rank();
    int determinant2 = matrix2.rank();
    int determinant4 = matrix4.rank();
    int determinant5 = matrix5.rank();

    EXPECT_EQ(determinant1, 2);
    EXPECT_EQ(determinant2, 3);
    EXPECT_EQ(determinant4, 2);
    EXPECT_EQ(determinant5, 1);
    ASSERT_THROW(matrix3.rank(), std::runtime_error);
}

TEST(MatrixCalculator, PowTest) {
    std::vector<std::vector<double>> input1 = {{1, 2},
                                               {3, 4}};
    std::vector<std::vector<double>> input2 = {{1.8,  2.34, 24.9},
                                               {0.56, 4.23, 21.4},
                                               {1,    2,    3}};
    std::vector<std::vector<double>> input3 = {};
    std::vector<std::vector<double>> input4 = {{1.8,  2.34, 24.9},
                                               {0.56, 4.23, 21.4}};
    std::vector<std::vector<double>> input5 = {{1.8}};

    MatrixCalculator matrix1(input1);
    MatrixCalculator matrix2(input2);
    MatrixCalculator matrix3(input3);
    MatrixCalculator matrix4(input4);
    MatrixCalculator matrix5(input5);

    MatrixCalculator res1 = matrix1.pow(4);
    MatrixCalculator res2 = matrix1.pow(0);
    MatrixCalculator res3 = matrix1.pow(1);
    MatrixCalculator res4 = matrix2.pow(2);
    MatrixCalculator res5 = matrix5.pow(7);

    std::vector<std::vector<double>> output1 = {{199, 290},
                                                {435, 634}};
    std::vector<std::vector<double>> output2 = {{1, 0},
                                                {0, 1}};
    std::vector<std::vector<double>> output3 = {{1, 2},
                                                {3, 4}};
    std::vector<std::vector<double>> output4 = {{29.4504, 63.9102, 169.596},
                                                {24.7768, 62.0033, 168.666},
                                                {5.92,    16.8,    76.7}};
    std::vector<std::vector<double>> output5 = {{61.2220032}};

    MatrixCalculator expected1(output1);
    MatrixCalculator expected2(output2);
    MatrixCalculator expected3(output3);
    MatrixCalculator expected4(output4);
    MatrixCalculator expected5(output5);

    EXPECT_EQ(res1, expected1);
    EXPECT_EQ(res2, expected2);
    EXPECT_EQ(res3, expected3);
    EXPECT_EQ(res4, expected4);
    EXPECT_EQ(res5, expected5);
    ASSERT_THROW(matrix3.pow(3), std::runtime_error);
    ASSERT_THROW(matrix4.pow(2), std::runtime_error);
}

TEST(MatrixCalculator, InverseTest) {
    std::vector<std::vector<double>> input1 = {{1, 2},
                                               {3, 4}};
    std::vector<std::vector<double>> input2 = {{1.1, 2, 3},
                                               {4,   5, 6},
                                               {1,   2, 3}};
    std::vector<std::vector<double>> input3 = {};
    std::vector<std::vector<double>> input4 = {{1.8,  2.34, 24.9},
                                               {0.56, 4.23, 21.4}};
    std::vector<std::vector<double>> input5 = {{1.8}};
    std::vector<std::vector<double>> input6 = {{1, 2, 3},
                                               {4, 5, 6},
                                               {0, 0, 0}};

    MatrixCalculator matrix1(input1);
    MatrixCalculator matrix2(input2);
    MatrixCalculator matrix3(input3);
    MatrixCalculator matrix4(input4);
    MatrixCalculator matrix5(input5);
    MatrixCalculator matrix6(input6);

    MatrixCalculator res1 = matrix1.inverse();
    MatrixCalculator res2 = matrix2.inverse();
    MatrixCalculator res5 = matrix5.inverse();

    std::vector<std::vector<double>> output1 = {{-2,  1},
                                                {1.5, -0.5}};
    std::vector<std::vector<double>> output2 = {{10, 0, -10},
                                                {-20, 1, 18},
                                                {10, -0.66666, -8.33333}};

    std::vector<std::vector<double>> output5 = {{0.55555}};

    MatrixCalculator expected1(output1);
    MatrixCalculator expected2(output2);
    MatrixCalculator expected5(output5);

    EXPECT_EQ(res1, expected1);
    EXPECT_EQ(res2, expected2);
    EXPECT_EQ(res5, expected5);
    ASSERT_THROW(matrix3.inverse(), std::runtime_error);
    ASSERT_THROW(matrix4.inverse(), std::runtime_error);
    ASSERT_THROW(matrix6.inverse(), std::runtime_error);
}
