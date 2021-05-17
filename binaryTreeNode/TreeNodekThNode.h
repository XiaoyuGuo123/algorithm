//
// Created by g fish on 2021/4/21.
//
#include "treeDepth.h"
#ifndef ALGORITHM_TREENODEKTHNODE_H
#define ALGORITHM_TREENODEKTHNODE_H
//二叉搜索树的第k大节点
//二叉搜索树的中序遍历，遍历序列的数值是递增排序的

int count = 0, res = 0;

int kthLargest(TreeNode* root, int k) {
    inorder(root, k);

    return res;
}

void inorder(TreeNode* root, int k) {
    if (!root) {
        return;
    }

    inorder(root -> right, k); // 右

    ++ count;
    if (count == k) {
        res = root -> val;
        return;
    }

    inorder(root -> left, k); // 左
}





#endif //ALGORITHM_TREENODEKTHNODE_H
