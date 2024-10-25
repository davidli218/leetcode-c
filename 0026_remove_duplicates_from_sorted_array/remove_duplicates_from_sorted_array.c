#include <stdlib.h>
#include <stdio.h>

/* 2024/10/25 | DuoPtr | T-100[O(N)] | M-19[O(1)] */
int removeDuplicates(int* nums, const int numsSize) {
    int inner_i = 0;
    int crt_num = *nums - 1;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != crt_num) {
            nums[inner_i++] = crt_num = nums[i];
        }
    }

    return inner_i;
}

int main() {
    /* Define test parameters */
    int nums[] = {1, 1, 2};

    /* Test function */
    const int result = removeDuplicates(nums, sizeof(nums) / sizeof(nums[0]));
    printf("Result: %d\n", result);
    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        printf("%d ", nums[i]);
    }

    return EXIT_SUCCESS;
}
