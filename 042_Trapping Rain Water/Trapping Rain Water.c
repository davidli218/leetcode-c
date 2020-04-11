//
// Created by David on 2020/4/4.
//

#include <stdio.h>

#define SOLUTION 1

#if SOLUTION == 1

/* 2020/4/4 4ms 5.8MB */
int arrayMax(const int *array, int arraySize) {
    int maxValue = *array;
    for (int i = 1; i < arraySize; ++i) {
        if (array[i] > maxValue)
            maxValue = array[i];
    }
    return maxValue;
}

int trap(int *height, int heightSize) {
    if (heightSize < 3)
        return 0;

    int drop = 0;
    int max_l = *height;
    int max_r = arrayMax(height + 1, heightSize - 1);
    for (int i = 1; i < heightSize - 1; ++i) {
        if (max_l < height[i])
            max_l = height[i];
        if (max_r == height[i])
            max_r = arrayMax(height + i + 1, heightSize - i - 1);
        if (max_r > height[i] && max_l > height[i])
            drop += (max_r > max_l ? max_l : max_r) - height[i];
    }
    return drop;
}

#endif

void trapTest(void) {
    int heightTest[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int res = trap(heightTest, sizeof(heightTest) / sizeof(heightTest[0]));
    printf("%d\n", res);
}

int main() {
    trapTest();
    return 0;
}