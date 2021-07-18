//
// Created by guoyu on 2021/5/7.
//
#include "treeDepth.h"
#ifndef ALGORITHM_ISSYSMMETRICAL_H
#define ALGORITHM_ISSYSMMETRICAL_H

//对称二叉树
bool isSymmertric(TreeNode* root){
    return isSymmertrical(root,root);
}
bool isSymmertrical(TreeNode* root1,TreeNode* root2){
    if(root1== nullptr&&root2== nullptr){
        return true;
    }
    if(root1== nullptr||root2== nullptr){
        return false;
    }
    if(root1->val!=root2->val){
        return false;
    }
    return isSymmertrical(root1->left,root2->right) && isSymmertrical(root1->right,root2->left);
}

#endif //ALGORITHM_ISSYSMMETRICAL_H
