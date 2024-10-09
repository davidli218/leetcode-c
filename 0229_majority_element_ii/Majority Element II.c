/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <stdio.h>

int cmp(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

int *majorityElement(int *nums, int numsSize, int *returnSize) {
    qsort(nums, numsSize, sizeof(*nums), cmp);

    int previous = *nums - 1;
    int current, previous_count = 0;

    for (int ptr = 0; ptr < numsSize; ++ptr) {
        current = *(nums + ptr);
        if (previous == current) {
            previous_count++;
        } else {

        }
    }

    return 0;
}

int main() {
    int testNums[] = {1, 1, 1, 3, 3, 2, 2, 2};
    int testNumSize = 8;

    int *retNums, *retSize;

    retNums = majorityElement(testNums, testNumSize, retSize);

    return 0;
}