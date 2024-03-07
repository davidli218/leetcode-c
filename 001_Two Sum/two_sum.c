//
// Created by David on 2020/4/3.
//
#include <stdlib.h>
#include <stdio.h>

#define SOLUTION 1

#if SOLUTION == 1

/* 2020/4/3 | BF | T-38 | M-39 */
int *twoSum(const int *nums, int numsSize, int target, int *returnSize) {
    int *ret = (int *) malloc(sizeof(int) * 2);
    *returnSize = 0;

    for (int i = 0; i < numsSize; ++i)
        for (int j = i + 1; j < numsSize; ++j)
            if (nums[i] + nums[j] == target) {
                ret[0] = i;
                ret[1] = j;
                *returnSize = 2;
                return ret;
            }

    return ret;
}

#endif

void run(void) {
    /* Define test case */
    int nums[] = {3, 3};
    int target = 6;

    /* Test twoSum function */
    int returnSize;
    int *result = twoSum(nums, sizeof(nums) / sizeof(*nums), target, &returnSize);

    /* Print return value */
    for (int i = 0; i < returnSize; ++i) { printf("%d\n", *(result + i)); }

    /* Release memory */
    free(result);
}

int main() {
    run();

    return EXIT_SUCCESS;
}
