//
// Created by david on 2020/7/30.
//

#include <math.h>

/* 2020/7/30 100.00% 50.00% */
int integerBreak(int n) {
    if (n <= 3) return n - 1;

    int q = n / 3, r = n % 3;

    /* Remainder = 0, 3^q */
    if (r == 0) return (int) pow(3, q);
    /* Remainder = 1，3^(q - 1) * 2 * 2 */
    else if (r == 1) return (int) pow(3, q - 1) * 4;
    /* Remainder = 2，3^q * 2 */
    return (int) pow(3, q) * 2;
}

int main(void) {

    int test_n = 24;

    return integerBreak(test_n);
}