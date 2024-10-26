#include <stdlib.h>
#include <stdio.h>

/* 2024/10/26 | Boyer-Moore | T-100[O(N)] | M-49[O(1)] */
int majorityElement(const int* nums, const int numsSize) {
    int candidate = 0;
    int count = 0;

    for (int i = 0; i < numsSize; ++i) {
        if (count == 0) {
            candidate = nums[i];
        }
        count += candidate == nums[i] ? 1 : -1;
    }

    return candidate;
}

int main() {
    /* Define test parameters */
    const int nums[] = {2, 2, 1, 1, 1, 2, 2};
    const int numsSize = sizeof(nums) / sizeof(nums[0]);

    /* Test function */
    const int result = majorityElement(nums, numsSize);
    printf("Majority element is: %d\n", result);

    return EXIT_SUCCESS;
}
