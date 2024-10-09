class Solution1:
    """ 2020/4/13 60ms 13.4MB """

    @staticmethod
    def rotate(matrix: list) -> None:
        matrix_size = len(matrix)
        for i in range(int(matrix_size / 2)):
            for j in range(int(matrix_size - 1 - 2 * i)):
                temp = matrix[matrix_size - 1 - i - j][i]
                matrix[matrix_size - 1 - i - j][i] = matrix[matrix_size - 1 - i][matrix_size - 1 - i - j]
                matrix[matrix_size - 1 - i][matrix_size - 1 - i - j] = matrix[i + j][matrix_size - 1 - i]
                matrix[i + j][matrix_size - 1 - i] = matrix[i][i + j]
                matrix[i][i + j] = temp


class Solution2:
    """ 2020/4/13 40ms 13.4MB """

    @staticmethod
    def rotate(matrix: list) -> None:
        matrix_size = len(matrix)
        for i in range(matrix_size):
            for j in range(1, matrix_size - i):
                temp = matrix[i][i + j]
                matrix[i][i + j] = matrix[i + j][i]
                matrix[i + j][i] = temp
        for i in range(matrix_size):
            for j in range(matrix_size // 2):
                temp = matrix[i][j]
                matrix[i][j] = matrix[i][matrix_size - j - 1]
                matrix[i][matrix_size - j - 1] = temp


if __name__ == '__main__':
    matrix_test = [[5, 1, 9, 11],
                   [2, 4, 8, 10],
                   [13, 3, 6, 7],
                   [15, 14, 12, 16]
                   ]
    Solution2.rotate(matrix_test)
    for i_ in matrix_test:
        print(i_)
