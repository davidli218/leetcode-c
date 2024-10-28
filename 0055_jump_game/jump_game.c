#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/* 2024/10/28 | Greedy | T-100[O(N)] | M-84[O(1)] */
bool canJump(const int* nums, const int numsSize) {
    if (*nums == 0) { return numsSize == 1 ? true : false; }

    int maxJ = 1, i = 0;

    for (i = 0; i < numsSize && maxJ > 0; ++i) {
        maxJ = nums[i] > maxJ - 1 ? nums[i] : maxJ - 1;
    }

    return i == numsSize;
}

int main() {
    /* Define test parameters */
    const int nums[] = {2, 3, 1, 1, 4};

    /* Test function */
    const bool result = canJump(nums, sizeof(nums) / sizeof(int));
    printf("Result is %s\n", result ? "true" : "false");


    return EXIT_SUCCESS;
}
