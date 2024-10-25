#include <stdio.h>
#include <stdlib.h>

/* 2024/10/25 | DuoPtr | T-100[O(M+N)] | M-05[O(1)] */
void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n) {
    int tail_1 = m - 1;
    int tail_2 = n - 1;
    int tail_merged = m + n - 1;

    while (tail_merged >= 0) {
        if (tail_1 < 0 || (tail_2 >= 0 && nums1[tail_1] < nums2[tail_2])) {
            nums1[tail_merged--] = nums2[tail_2--];
        } else {
            nums1[tail_merged--] = nums1[tail_1--];
        }
    }
}

int main() {
    /* Define test parameters */
    int nums1[] = {1, 2, 3, 0, 0, 0};
    int nums2[] = {2, 5, 6};

    /* Test function */
    merge(nums1, 6, 3, nums2, 3, 3);
    for (int i = 0; i < 6; i++) {
        printf("%d ", nums1[i]);
    }

    return EXIT_SUCCESS;
}
