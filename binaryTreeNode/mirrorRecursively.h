//
// Created by guoyu on 2021/4/28.
//
#include "treeDepth.h"
#ifndef ALGORITHM_MIRRORRECURSIVELY_H
#define ALGORITHM_MIRRORRECURSIVELY_H
//二叉树的镜像
TreeNode* mirrorTree(TreeNode* root) {
    if(root==nullptr) return nullptr;

    TreeNode *pTemp=root->left;
    root->left=mirrorTree(root->right);
    root->right=mirrorTree(pTemp);
    return root;
}

#endif //ALGORITHM_MIRRORRECURSIVELY_H
