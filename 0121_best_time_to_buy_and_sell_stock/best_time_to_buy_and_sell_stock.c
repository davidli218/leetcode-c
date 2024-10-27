#include <stdlib.h>
#include <stdio.h>

/* 2024/10/27 | COMMON | T-100[O(N)] | M-56[O(1)] */
int maxProfit(const int* prices, const int pricesSize) {
    int maxProfit = 0;
    int minPrice = prices[0];

    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else if (prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;
        }
    }

    return maxProfit;
}

int main() {
    /* Define test parameters */
    const int prices[] = {7, 1, 5, 3, 6, 4};
    const int pricesSize = sizeof(prices) / sizeof(prices[0]);

    /* Test function */
    const int result = maxProfit(prices, pricesSize);
    printf("Result: %d\n", result);

    return EXIT_SUCCESS;
}
