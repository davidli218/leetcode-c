//
// Created by teiiri on 2021/6/4.
//

#include <stdlib.h>
#include <stdio.h>

#define SOLUTION 1

struct ListNode {
    int val;
    struct ListNode *next;
};

#if SOLUTION == 1

/* 2021/6/11 DuoPtr Time>98% Mem>73% */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL)
        return NULL;

    int flagA = 1, flagB = 1;
    struct ListNode *ptrA = headA, *ptrB = headB;

    while (flagA || flagB) {
        if (ptrA->next == NULL) {
            ptrA = headB;
            flagA = 0;
        } else ptrA = ptrA->next;
        if (ptrB->next == NULL) {
            ptrB = headA;
            flagB = 0;
        } else ptrB = ptrB->next;
    }

    while (ptrA != NULL) {
        if (ptrA == ptrB)
            return ptrA;

        ptrA = ptrA->next;
        ptrB = ptrB->next;
    }

    return NULL;
}

#elif SOLUTION == 2

/* 2021/6/11 DuoPtr Time>76% Mem>17% */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *ptrA = headA, *ptrB = headB;

    while (ptrA != ptrB) {
        ptrA = ptrA != NULL ? ptrA->next : headB;
        ptrB = ptrB != NULL ? ptrB->next : headA;
    }

    return ptrA;
}

#endif

int main(void) {
    struct ListNode *testResult;

    struct ListNode *a1 = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *a2 = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *b1 = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *b2 = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *b3 = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *c1 = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *c2 = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *c3 = (struct ListNode *) malloc(sizeof(struct ListNode));

    a1->next = a2;
    a2->next = c1;
    b1->next = b2;
    b2->next = b3;
    b3->next = c1;
    c1->next = c2;
    c2->next = c3;
    c3->next = NULL;

    a1->val = 4;
    a2->val = 1;
    b1->val = 5;
    b2->val = 0;
    b3->val = 2;
    c1->val = 8;
    c2->val = 9;
    c3->val = 5;

    testResult = getIntersectionNode(a1, b1);

    if (testResult != NULL)
        printf("Intersected at '%d'\n", testResult->val);
    else
        printf("No intersection\n");

    return 0;
}