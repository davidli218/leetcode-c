#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 2021/6/11 | SlidingWindow | T-61 | M-83 */
int lengthOfLongestSubstring(char* s) {
    const int len = (int)strlen(s);
    int left = 0, right = -1;
    char freq[256] = {0};
    int maxLen = 0;

    /* 维护一个滑动窗口, 窗口内的字符不重复.
     * 如果右端下一个字符不在窗口内, 则右端右移, 否则左端右移. */
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
    /* Define test parameters */
    char* testStr = "aab";

    /* Test function */
    printf("%d", lengthOfLongestSubstring(testStr));

    return EXIT_SUCCESS;
}
