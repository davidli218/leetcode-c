//
// Created by david on 2020/7/28.
//

#include <stdlib.h>
#include <stdio.h>

#define  max_d(x, y)    ((x) > (y) ? (x) : (y))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/* 2020/7/28 DFP O(nums of node) O(depth of tree) */
int maxDepth(struct TreeNode *root) {
    if (root == NULL)
        return 0;
    return max_d(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int main(int argc, char *argv[]) {
    /*
       Depth:1        A
                     / \
       Depth:2      B   D
                   /
       Depth:3    C
    */
    struct TreeNode *testTree = (struct TreeNode *) malloc(sizeof(struct TreeNode)); /* A */
    testTree->left = (struct TreeNode *) malloc(sizeof(struct TreeNode)); /* B */
    testTree->left->left = (struct TreeNode *) malloc(sizeof(struct TreeNode)); /* C */
    testTree->left->right = NULL;
    testTree->left->left->left = NULL;
    testTree->left->left->right = NULL;
    testTree->right = (struct TreeNode *) malloc(sizeof(struct TreeNode)); /* D */
    testTree->right->left = NULL;
    testTree->right->right = NULL;

    printf("Depth:%d\n", maxDepth(testTree));

    return EXIT_SUCCESS;
}