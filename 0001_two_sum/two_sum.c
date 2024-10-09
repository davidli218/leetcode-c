#include <stdlib.h>
#include <stdio.h>

#define SOLUTION 1

#if SOLUTION == 1
/* 2020/4/3 | BF | T-38 | M-39 */
int* twoSum(const int* nums, int numsSize, int target, int* returnSize) {
    int* ret = malloc(sizeof(int) * 2);
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

int main() {
    /* Define test parameters */
    const int nums[] = {3, 3};
    const int target = 6;

    /* Test function */
    int returnSize;
    int* result = twoSum(nums, sizeof(nums) / sizeof(*nums), target, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d\n", *(result + i));
    }

    /* Clean up */
    free(result);

    return EXIT_SUCCESS;
}
