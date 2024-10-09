//
// Created by David on 2020/4/9.
//

#include <stdio.h>

/* 2020/4/10 0ms 5.6MB */
char *longestCommonPrefix(char (*strs)[10], int strsSize) {
    //char *longestCommonPrefix(char **strs, int strsSize) in LeetCode
    if (strsSize == 0) return "";
    char temp;
    int i = -1;
    while ((temp = strs[0][++i]) != '\0') {
        for (int j = 0; j < strsSize; ++j) {
            if (temp != strs[j][i]) {
                strs[0][i] = '\0';
                return strs[0];
            }
        }
    }
    return strs[0];
}

int main() {
    char strsTest[][10] = {"flower", "flow", "flight"};
    printf("%s", longestCommonPrefix(strsTest, sizeof(strsTest) / sizeof(*strsTest)));
    return 0;
}
