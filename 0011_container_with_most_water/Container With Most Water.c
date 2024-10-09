//
// Created by david on 2020/4/5.
//

#include <stdio.h>

#define SOLUTION 2

#if SOLUTION == 1

/* 20020/4/5 双指针 8ms 6.4MB */
int maxArea(const int *height, int heightSize) {
    if (heightSize < 2)
        return 0;

    int *ptr_l = (int *) height;
    int *ptr_r = (int *) height + heightSize - 1;
    int maxValue = (int) (ptr_r - ptr_l) * ((*ptr_l < *ptr_r) ? *ptr_l : *ptr_r);

    while (ptr_r != ptr_l) {
        if (*ptr_l <= *ptr_r) ptr_l++;
        else ptr_r--;
        maxValue = (maxValue > (int) (ptr_r - ptr_l) * ((*ptr_l < *ptr_r) ? *ptr_l : *ptr_r)) ?
                   maxValue : (int) (ptr_r - ptr_l) * ((*ptr_l < *ptr_r) ? *ptr_l : *ptr_r);
    }
    return maxValue;
}

#elif SOLUTION == 2

/* 20020/4/5 双指针 */
int maxArea(const int *height, int heightSize) {
    int temp_area;
    int maxValue = 0;
    int ptr_l = 0;
    int ptr_r = heightSize - 1;

    while (ptr_l < ptr_r) {
        if (height[ptr_l] < height[ptr_r]) {
            temp_area = height[ptr_l] * (ptr_r - ptr_l);
            ptr_l++;
        } else {
            temp_area = height[ptr_r] * (ptr_r - ptr_l);
            ptr_r--;
        }

        maxValue = maxValue < temp_area ? temp_area : maxValue;
    }
    return maxValue;
}

#endif

void maxAreaTest(void) {
    int height[] = {1, 1};
    printf("%d\n", maxArea(height, sizeof(height) / sizeof(height[0])));
}

int main() {
    maxAreaTest();
    return 0;
}