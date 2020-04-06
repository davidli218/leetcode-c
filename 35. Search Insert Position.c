//
// Created by david on 2020/4/6.
//
#include <stdio.h>
#include "35. Search Insert Position.h"

#define SOLUTION 2

#if (SOLUTION == 1)

/* 20204/6 二分法 12ms 5.8MB */
int searchInsert(const int *nums, int numsSize, int target) {
    int l = 0;
    int r = numsSize - 1;
    if (target > *(nums + numsSize - 1))
        return numsSize;
    if (target <= *nums || numsSize < 2)
        return 0;
    while (r - l != 1) {
        if (nums[(r + l) / 2] > target) {
            r = (r + l) / 2;
            if (nums[r] == target) return r;
        } else {
            l = (r + l) / 2;
            if (nums[l] == target) return l;
        }
    }
    return r;
}

#elif (SOLUTION == 2)

/* 20204/6 二分法 4ms 5.7MB */
int searchInsert(const int *nums, int numsSize, int target) {
    int low = 0, high = numsSize - 1;
    int mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

#endif

void searchInsertTest(void) {
    int numsTest[] = {1, 3, 5, 6};
    int targetTest = 6;
    printf("%d", searchInsert(numsTest, sizeof(numsTest) / sizeof(numsTest[0]), targetTest));
}