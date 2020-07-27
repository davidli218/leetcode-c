//
// Created by david on 2020/7/27.
//

#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/* 2020/7/27 95.01% 100.00% */
struct ListNode *addTwoNumbers(const struct ListNode *l1, const struct ListNode *l2) {
    int aFlag = 0, tmp;
    struct ListNode *ret = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *p = ret;

    while (1) {
        tmp = l1->val + l2->val + aFlag;
        p->val = tmp % 10;
        aFlag = tmp / 10;

        l1 = l1->next;
        l2 = l2->next;
        if (l1 == NULL || l2 == NULL)
            break;
        p = p->next = (struct ListNode *) malloc(sizeof(struct ListNode));
    }

    if ((l1 = (l1 == NULL) ? l2 : l1) != NULL) {
        while (l1 != NULL) {
            p = p->next = (struct ListNode *) malloc(sizeof(struct ListNode));

            tmp = l1->val + aFlag;
            p->val = tmp % 10;
            aFlag = tmp / 10;

            l1 = l1->next;
        }
    }

    if (aFlag) {
        p = p->next = (struct ListNode *) malloc(sizeof(struct ListNode));
        p->val = aFlag;
    }

    p->next = NULL;
    return ret;
}

int main(int argc, char *argv[]) {
    struct ListNode *test_a = (struct ListNode *) malloc(sizeof(struct ListNode));
    test_a->val = 1;
    test_a->next = (struct ListNode *) malloc(sizeof(struct ListNode));
    test_a->next->val = 8;
    test_a->next->next = NULL;

    struct ListNode *test_b = (struct ListNode *) malloc(sizeof(struct ListNode));
    test_b->val = 0;
    test_b->next = NULL;

    addTwoNumbers(test_a, test_b);

    return EXIT_SUCCESS;
}