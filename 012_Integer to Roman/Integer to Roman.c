//
// Created by david on 2021/5/14.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/* 2021/05/14 92.40% 22.28% */
char *intToRoman(int num) {
    if (num < 1 || num > 3999) {
        return "Out of range. Only (1 <= num <= 3999) is valid.";
    }

    char *map[4][10] = {
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"", "M", "MM", "MMM"}
    };

    char *ret = (char *) malloc(sizeof(char) * 16);
    memset(ret, 0, 16);

    for (int i = 3; i > -1; --i)
        strcat(ret, map[i][num / (int) pow(10, i) % 10]);

    return ret;
}


int main(void) {
    printf("1994 = %s", intToRoman(1994));

    return 0;
}