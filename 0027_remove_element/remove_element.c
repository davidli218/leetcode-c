#include <stdlib.h>
#include <stdio.h>

/* 2024/10/25 | DuoPtr | T-100[O(N)] | M-19[O(1)] */
int removeElement(int* nums, const int numsSize, const int val) {
    int inner_i = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[inner_i++] = nums[i];
        }
    }

    return inner_i;
}

int main() {
    /* Define test parameters */
    int nums[] = {3, 2, 2, 3};
    const int val = 3;
    const int numsSize = sizeof(nums) / sizeof(nums[0]);

    /* Test function */
    const int result = removeElement(nums, numsSize, val);
    printf("Result: %d\n", result);
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }

    return EXIT_SUCCESS;
}
