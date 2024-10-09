//
// Created by david on 2020/8/2.
//

#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/* 2020/8/2 递归 88.18% 40.00% */
void flatten(struct TreeNode *root) {
    if (root == NULL)
        return;

    /* 左右子树转换为单链表 */
    flatten(root->left);
    flatten(root->right);

    /* 暂存右子树 */
    struct TreeNode *temp = root->right;
    /* 左子树接到根的右侧 */
    root->right = root->left;
    /* 左子树置空 */
    root->left = NULL;

    /* 接上右子树 */
    while (root->right != NULL)
        root = root->right;
    root->right = temp;
}