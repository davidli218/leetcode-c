#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

/* 2020/7/27 | BF | T-12 | M-79 */
struct ListNode* addTwoNumbers(const struct ListNode* l1, const struct ListNode* l2) {
    struct ListNode* head_ptr = malloc(sizeof(struct ListNode));
    struct ListNode* ret_ptr = head_ptr;
    int carry = 0;

    while (l1 || l2 || carry) {
        const int val1 = l1 ? l1->val : 0;
        const int val2 = l2 ? l2->val : 0;
        const int sum = val1 + val2 + carry;

        head_ptr->val = sum % 10;
        carry = sum / 10;

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;

        if (l1 || l2 || carry) {
            head_ptr->next = malloc(sizeof(struct ListNode));
            head_ptr = head_ptr->next;
        }
    }

    head_ptr->next = NULL;

    return ret_ptr;
}

void freeLinkedList(struct ListNode* head) {
    while (head != NULL) {
        struct ListNode* tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    /* Define test parameters */
    struct ListNode* test_a = malloc(sizeof(struct ListNode));
    struct ListNode* test_b = malloc(sizeof(struct ListNode));
    test_a->val = 1;
    test_a->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    test_a->next->val = 8;
    test_a->next->next = NULL;
    test_b->val = 0;
    test_b->next = NULL;

    /* Test function */
    struct ListNode* ret = addTwoNumbers(test_a, test_b);
    const struct ListNode* tmp = ret;
    do {
        printf("%d\n", tmp->val);
    } while ((tmp = tmp->next) != NULL);

    /* Clean up */
    freeLinkedList(test_a);
    freeLinkedList(test_b);
    freeLinkedList(ret);

    return EXIT_SUCCESS;
}
