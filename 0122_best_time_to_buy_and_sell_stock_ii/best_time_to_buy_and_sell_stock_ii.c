#include <stdlib.h>
#include <stdio.h>

/* 2024/10/27 | COMMON | T-100[O(N)] | M-42[O(1)] */
int maxProfit(const int* prices, const int pricesSize) {
    int totalProfit = 0, crtHold = prices[0];

    for (int i = 0; i < pricesSize; ++i) {
        if (prices[i] > crtHold) { totalProfit += prices[i] - crtHold; }
        crtHold = prices[i];
    }

    return totalProfit;
}

int main() {
    /* Define test parameters */
    const int test[] = {7, 1, 5, 3, 6, 4};
    const int testSize = sizeof(test) / sizeof(test[0]);

    /* Test function */
    const int result = maxProfit(test, testSize);
    printf("Result: %d\n", result);

    return EXIT_SUCCESS;
}
