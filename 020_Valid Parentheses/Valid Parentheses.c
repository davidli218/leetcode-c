#include <stdbool.h>

/* 2020/9/15 O(n) O(n) */
bool isValid(char *s) {
    char l[10240], *l_p = l;
    for (; *s != '\0'; s++)
        if (*s == '(' || *s == '[' || *s == '{')
            *(l_p++) = *s;
        else if (l_p == l || (*s - *(--l_p) != 1 && *s - *(l_p) != 2))
            return false;
    return l_p == l ? true : false;
}