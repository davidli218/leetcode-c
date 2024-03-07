//
// Created by david on 2020/7/27.
//

#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/* 2020/7/27 | BF | T-12 | M-79 */
struct ListNode *addTwoNumbers(const struct ListNode *l1, const struct ListNode *l2) {
    int tmp, carry = 0;
    struct ListNode *ret_head = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *ret_ptr = ret_head;

    /* 1. Handle the common part */
    while (1) {
        tmp = l1->val + l2->val + carry;
        ret_ptr->val = tmp % 10;
        carry = tmp / 10;

        l1 = l1->next;
        l2 = l2->next;
        if (l1 == NULL || l2 == NULL)
            break;

        ret_ptr = ret_ptr->next = (struct ListNode *) malloc(sizeof(struct ListNode));
    }

    /* 2. Handle the remaining list */
    if ((l1 = (l1 == NULL) ? l2 : l1) != NULL) {
        while (l1 != NULL) {
            ret_ptr = ret_ptr->next = (struct ListNode *) malloc(sizeof(struct ListNode));

            tmp = l1->val + carry;
            ret_ptr->val = tmp % 10;
            carry = tmp / 10;

            l1 = l1->next;
        }
    }

    /* 3. Handle the remaining carry */
    if (carry) {
        ret_ptr = ret_ptr->next = (struct ListNode *) malloc(sizeof(struct ListNode));
        ret_ptr->val = carry;
    }

    /* 4. Terminate the list */
    ret_ptr->next = NULL;

    return ret_head;
}

void freeLinkedList(struct ListNode *head) {
    struct ListNode *tmp;

    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void run(void) {
    struct ListNode *ret, *tmp;

    /* Define test case */
    struct ListNode *test_a = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *test_b = (struct ListNode *) malloc(sizeof(struct ListNode));
    test_a->val = 1;
    test_a->next = (struct ListNode *) malloc(sizeof(struct ListNode));
    test_a->next->val = 8;
    test_a->next->next = NULL;
    test_b->val = 0;
    test_b->next = NULL;

    /* Test addTwoNumbers function */
    ret = addTwoNumbers(test_a, test_b);

    /* Print return value */
    tmp = ret;
    do { printf("%d\n", tmp->val); } while ((tmp = tmp->next) != NULL);

    /* Release memory */
    freeLinkedList(test_a);
    freeLinkedList(test_b);
    freeLinkedList(ret);
}

int main() {
    run();

    return EXIT_SUCCESS;
}
