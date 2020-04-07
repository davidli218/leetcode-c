//
// Created by David on 2020/4/3.
//
#include <stdlib.h>
#include <stdio.h>
#include "Two Sum.h"

#define SOLUTION 1

#if SOLUTION == 1

/* 2020/4/3 216ms 6MB */
int *twoSum(const int *nums, int numsSize, int target, int *returnSize) {
    int *res = (int *) malloc(sizeof(int) * 2);
    *returnSize = 0;
    for (int i = 0; i < numsSize; ++i) {
        for (int j = i + 1; j < numsSize; ++j) {
            if (nums[i] + nums[j] == target) {
                res[0] = i;
                res[1] = j;
                *returnSize = 2;
                return res;
            }
        }
    }
    return res;
}

#endif

void twoSumTest(void) {
    int numsTest[] = {3, 3};
    int targetTest = 6;
    int resSize;
    int *res = twoSum(numsTest, sizeof(numsTest) / sizeof(numsTest[0]), targetTest, &resSize);
    for (int i = 0; i < resSize; ++i) {
        printf("%d\n", *(res + i));
    }
}

int main() {
    twoSumTest();
    return 0;
}