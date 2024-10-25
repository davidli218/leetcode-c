#include <stdlib.h>
#include <stdio.h>

/* 2024/10/25 | DuoPtr | T-94[O(N)] | M-88[O(1)] */
int removeDuplicates(int* nums, const int numsSize) {
    int inner_i = 0;
    int counter = 0;
    int crt_num = *nums - 1;

    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] != crt_num) {
            nums[inner_i++] = crt_num = nums[i];
            counter = 0;
        } else if (nums[i] == crt_num && counter < 1) {
            nums[inner_i++] = nums[i];
            counter++;
        }
    }

    return inner_i;
}

int main() {
    /* Define test parameters */
    int nums[] = {1, 1, 1, 2, 2, 3};

    /* Test function */
    const int result = removeDuplicates(nums, sizeof(nums) / sizeof(nums[0]));
    printf("Result: %d\n", result);
    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        printf("%d ", nums[i]);
    }

    return EXIT_SUCCESS;
}
