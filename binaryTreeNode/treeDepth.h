//
// Created by g fish on 2021/4/10.
//

#ifndef ALGORITHM_TREEDEPTH_H
#define ALGORITHM_TREEDEPTH_H

struct TreeNode{
    int     val;
    TreeNode *left;
    TreeNode *right;
};

//base case: 节点==nullptr, 深度=0
//问左子树 要信息，问右子树要信息
//条件是什么：左右子树，谁的大，取谁加一
int TreeDepth(TreeNode *pRoot){
    if(pRoot== nullptr) return 0;
    int left=TreeDepth(pRoot->left);
    int right=TreeDepth(pRoot->right);
    return (left>rigth)?(left+1):(right+1);
}

#endif //ALGORITHM_TREEDEPTH_H
