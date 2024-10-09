//
// Created by david on 2020/8/3.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define Max(x, y) ((x) > (y) ? (x) : (y))

/* 2020/8/6 Simulation O(MAX(len(num1), len(num2))) O(1) */
char *addStrings(char *num1, char *num2) {
    int i = strlen(num1) - 1, j = strlen(num2) - 1, add = 0;
    char *ret = (char *) malloc(sizeof(char) * (Max(i, j) + 3));
    int len = 0;
    while (i >= 0 || j >= 0 || add != 0) {
        int x = i >= 0 ? num1[i] - '0' : 0;
        int y = j >= 0 ? num2[j] - '0' : 0;
        int result = x + y + add;
        ret[len++] = '0' + result % 10;
        add = result / 10;
        i--, j--;
    }

    for (int i = 0; 2 * i < len; i++) {
        int t = ret[i];
        ret[i] = ret[len - i - 1], ret[len - i - 1] = t;
    }
    ret[len++] = 0;
    return ret;
}

int main(int argc, char *argv[]) {
    char *test_num1 = "23";
    char *test_num2 = "12";

    printf("%s\n", addStrings(test_num1, test_num2));

    return EXIT_SUCCESS;
}