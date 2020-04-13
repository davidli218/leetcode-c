//
// Created by david on 2020/4/13.
//

/* AS SAME AS A01.07_Rotate Matrix LCCI */

#include <stdio.h>

/* 2020/4/13 原地旋转 8ms 5.9MB */
void rotate(int (*matrix)[5], int matrixSize, int *matrixColSize) {
    //void rotate(int** matrix, int matrixSize, int* matrixColSize) in LeetCode
    int temp;
    for (int i = 0; i < 1 + (matrixSize - 1) / 2; ++i) {
        for (int j = 0; j < matrixSize - 2 * i - 1; ++j) {
            temp = matrix[matrixSize - 1 - i - j][i];
            matrix[matrixSize - 1 - i - j][i] = matrix[matrixSize - 1 - i][matrixSize - 1 - i - j];
            matrix[matrixSize - 1 - i][matrixSize - 1 - i - j] = matrix[i + j][matrixSize - 1 - i];
            matrix[i + j][matrixSize - 1 - i] = matrix[i][i + j];
            matrix[i][i + j] = temp;
        }
    }
}

int main() {
    int matrixTest[5][5] = {
            {5,  1,  9,  11, 21},
            {2,  4,  8,  10, 23},
            {13, 3,  6,  7,  26},
            {15, 14, 12, 16, 27},
            {31, 33, 35, 37, 51}};
    rotate(matrixTest, sizeof(*matrixTest) / sizeof(**matrixTest), 0);
    /* 打印结果 */
    for (int i = 0; i < sizeof(*matrixTest) / sizeof(**matrixTest); ++i) {
        for (int j = 0; j < sizeof(*matrixTest) / sizeof(**matrixTest); ++j) {
            printf("%d\t", *(*(matrixTest + i) + j));
        }
        printf("\n");
    }
    return 0;
}