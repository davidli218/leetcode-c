//
// Created by David on 2020/5/6.
//

struct ListNode {
    int val;
    struct ListNode *next;
};

/* 2020/5/6 0ms 5.4MB */
int getDecimalValue(struct ListNode *head) {
    unsigned value = 0;

    while (head) {
        value = value << 1u | (unsigned) head->val;
        //value = 2 * value + head->val;
        head = head->next;
    }

    return (int) value;
}