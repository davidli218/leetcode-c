#include <stdlib.h>
#include <stdio.h>

/* 2024/10/26 | COMMON | T-100[O(N)] | M-21[[O(1)]] */
void rotate(int* nums, const int numsSize, const int k) {
    if (k == 0 || numsSize == 1) return;

    int temp = nums[0], crt_i = 0, start_i = 0;

    for (int i = 0; i < numsSize; ++i) {
        const int next_i = (crt_i + k) % numsSize;

        nums[next_i] = nums[next_i] ^ temp;
        temp = nums[next_i] ^ temp;
        nums[next_i] = nums[next_i] ^ temp;

        crt_i = next_i;

        if (crt_i == start_i && i < numsSize - 1) {
            start_i = ++crt_i;
            temp = nums[crt_i];
        }
    }
}

int main() {
    /* Define test parameters */
    int testNums[] = {-1, -100, 3, 99};
    const int testK = 2;

    /* Test function */
    rotate(testNums, sizeof(testNums) / sizeof(testNums[0]), testK);
    for (int i = 0; i < sizeof(testNums) / sizeof(testNums[0]); i++) {
        printf("%d ", testNums[i]);
    }

    return EXIT_SUCCESS;
}
