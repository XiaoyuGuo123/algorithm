//
// Created by g fish on 2021/4/10.
//
#include "treeDepth.h"
#ifndef ALGORITHM_ISBALANCED_H
#define ALGORITHM_ISBALANCED_H

bool IsBalanced(TreeNode *pRoot){
    if(pRoot== nullptr) return true;
    int left=TreeDepth(pRoot->left);
    int right=TreeDepth(pRoot->right);
    int diff=left-right;
    if(diff>1||diff<-1) return false;
    return IsBalanced(pRoot->left) &&IsBalanced(pRoot->right);
}

//判断 平衡节点
bool IsBalancedFunc(TreeNode *pRoot,int *depth){
    if(pRoot== nullptr){
        depth=0;
        return true;
    }
    int left,right;
    if(IsBalancedFunc(pRoot->left,&left)&&IsBalancedFunc(pRoot->right,&right)){
        int diff=left-right;
        if(diff<=1&&diff>=-1){
            *depth=1+(left>right?left:right);
            return true;
        }
    }
    return false;
}

bool IsBalance(TreeNode *pRoot){
    int depth=0;
    return IsBalancedFunc(pRoot,&depth);
}

#endif //ALGORITHM_ISBALANCED_H
