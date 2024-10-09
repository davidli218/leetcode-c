//
// Created by david on 2020/7/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 2020/7/15 DP 0 ms 5.2 MB */
int numTrees(int n) {
    if (n == 0) return 0;

    int ansArr[n + 1];
    memset(ansArr, 0, sizeof(ansArr));
    ansArr[0] = ansArr[1] = 1;

    for (int i = 2; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            ansArr[i] += ansArr[j - 1] * ansArr[i - j];

    return ansArr[n];
}

int main(int argc, char const *argv[]) {
    int testNum = 4;

    printf("Given n = %d, there are a total of %d unique BSTs", testNum, numTrees(testNum));

    return EXIT_SUCCESS;
}