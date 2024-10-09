//
// Created by David on 2020/12/10.
//

#include <stdio.h>
#include <stdbool.h>

#define SOLUTION 1

#if SOLUTION == 0

bool lemonadeChange(const int *bills, int billsSize) {
    int five = 0, ten = 0;

    for (int i = 0; i < billsSize; ++i)
        if (bills[i] == 5)
            five++;
        else if (bills[i] == 10)
            if (five == 0)
                return false;
            else
                five--, ten++;
        else if (five > 0 && ten > 0)
            five--, ten--;
        else if (five >= 3)
            five -= 3;
        else
            return false;
    return true;
}

#elif SOLUTION == 1

bool lemonadeChange(const int *bills, int billsSize) {
    int i = 0;
    int five = 0, ten = 0;
    for (; i ^ billsSize; ++i) {
        switch (bills[i]) {
            case 5:
                five++;
                break;
            case 10:
                ten++, five--;
                break;
            case 20:
                (ten) ? (ten--, five--) : (five -= 3);
                break;
        }
        if (five < 0)
            break;
    }
    return i == billsSize;
}


#endif

int main(void) {
    int testBills[] = {5, 5, 5, 10, 20};
    bool ans = lemonadeChange(testBills, sizeof(testBills));
    printf("%d", ans);

    return 0;
}