//
// Created by teiiri on 2021/6/11.
//

#include <stdio.h>
#include <string.h>

/* 2021/6/11 Time>61% Mem>83% */
int lengthOfLongestSubstring(char *s) {
    int maxLen = 0;
    int len = (int) strlen(s);
    int freq[256] = {0};
    int left = 0, right = -1;

    while (left < len) {
        if (right < len - 1 && freq[s[right + 1]] == 0)
            freq[s[++right]]++;
        else
            freq[s[left++]]--;

        maxLen = maxLen > right - left + 1 ? maxLen : right - left + 1;
    }

    return maxLen;
}

int main(void) {
    char *testStr = "aab";
    printf("%d", lengthOfLongestSubstring(testStr));

    return 0;
}