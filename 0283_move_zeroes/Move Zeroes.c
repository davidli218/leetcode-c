//
// Created by David on 2020/5/7.
//

#include <stdio.h>

#define SOLUTION 1

#if SOLUTION == 0

/* 2020/5/7 28ms 7.4MB */
void moveZeroes(int *nums, int numsSize) {
    for (int j, i = 0; i < numsSize; ++i)
        if (nums[i] == 0) {
            j = i--;
            while (++j < numsSize)
                nums[j - 1] = nums[j];
            nums[--numsSize] = 0;
        }
}

#elif SOLUTION == 1

/* 2020/5/7 16ms 7.5MB */
void moveZeroes(int *nums, int numsSize) {
    int zeroCount = 0;
    for (int i = 0; i < numsSize; i++)
        if (nums[i] != 0)
            nums[zeroCount++] = nums[i];
    while (zeroCount < numsSize)
        nums[zeroCount++] = 0;
}

#endif

int main() {
    int testNums[] = {0, 0, 1};
    moveZeroes(testNums, sizeof(testNums) / sizeof(*testNums));
    for (int i = 0; i < sizeof(testNums) / sizeof(*testNums); i++)
        printf("%d", testNums[i]);
    return 0;
}