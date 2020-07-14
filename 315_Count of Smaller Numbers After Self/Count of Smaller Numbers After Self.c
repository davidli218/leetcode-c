//
// Created by david on 2020/7/11.
//

/**
 * 偷懒了好久
 * 今天必须一个
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SOLUTION 1

#if SOLUTION == 0

/* 2020/7/11 暴力法 超出时间限制 */
int *countSmaller(const int *nums, int numsSize, int *returnSize) {
    if (numsSize == 0 || nums == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int *ans = (int *) malloc(sizeof(int) * numsSize);
    memset(ans, 0, sizeof(int) * numsSize);  //Initialize the array with 0

    for (int i = 0; i < numsSize; ++i)
        for (int j = 1; j < numsSize - i; ++j)
            if (nums[i] > nums[i + j])
                ans[i]++;

    *returnSize = numsSize;
    return ans;
}

#elif SOLUTION == 1

/* 2020/7/13 二分查找法 408ms 8.7MB */
int binarySearch(const int *nums, int numsSize, int key) {
    int left = 0, right = numsSize - 1, mid;

    while (left <= right) {
        mid = (left + right) / 2;
        if (nums[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    while (left != 0 && nums[left] == nums[left - 1])
        --left;

    return left;
}

void insert(int *arr, int num, int index, int moveRange) {
    for (int i = moveRange - 1; i > -1; --i)
        *(arr + index + i + 1) = *(arr + index + i);

    *(arr + index) = num;
}

int *countSmaller(const int *nums, int numsSize, int *returnSize) {
    if (numsSize == 0 || nums == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int *ans = (int *) malloc(sizeof(int) * numsSize);
    int *tempArr = (int *) malloc(sizeof(int) * numsSize);
    memset(tempArr, 0x3f, sizeof(int) * numsSize); // 初始化数组为极大值

    for (int i = numsSize - 1; i > -1; --i) {
        ans[i] = binarySearch(tempArr, numsSize, nums[i]);
        insert(tempArr, nums[i], ans[i], numsSize - 1 - i - ans[i]);
    }

    free(tempArr);
    tempArr = NULL;
    *returnSize = numsSize;
    return ans;
}

#endif

int main(int argc, char const *argv[]) {
    int testNums[] = {2, 0, 1};
    int *testResult = NULL, testResultSize;

    testResult = countSmaller(testNums, sizeof(testNums) / sizeof(*testNums), &testResultSize);

    for (int i = 0; i < testResultSize; ++i)
        printf("%d, ", *(testResult + i));

    free(testResult);
    return 0;
}