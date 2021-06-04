//
// Created by teiiri on 2021/6/4.
//

#include <stdio.h>

/* 2021/05/27 100.00% 57.10% */
int hammingDistance(int x, int y) {
    int ans = 0;

    for (int i = x ^ y; i > 0; i -= (i & -i))
        ans++;

    return ans;
}

int main(void) {
    printf("%d\n", hammingDistance(1, 4));

    return 0;
}