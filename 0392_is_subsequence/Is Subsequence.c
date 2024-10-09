//
// Created by david on 2020/7/27.
//

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

/* 2020/7/27 双指针 4ms 5.3MB */
bool isSubsequence(const char *s, const char *t) {
    if (*s == '\0')
        return true;

    int i = 0, j = 0;

    while (*(t + i) != '\0') {
        if (*(s + j) == *(t + i)) {
            j++;
            if (*(s + j) == '\0')
                return true;
        }
        i++;
    }

    return false;
}

int main(int argc, char *argv[]) {
    char *test_s = "abc";
    char *test_t = "asafcrfb";

    bool res = isSubsequence(test_s, test_t);

    printf("%d", res);

    return EXIT_SUCCESS;
}