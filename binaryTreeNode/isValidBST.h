//
// Created by gfish on 2021/7/18.
//

#ifndef ALGORITHM_ISVALIDBST_H
#define ALGORITHM_ISVALIDBST_H
/*
 * 判断是否是二叉搜索树
 *  二叉搜索树的中序遍历是递增的
 *  将元素放入栈中，先进后出
 * */
bool isValidBST(TreeNode* root) {
    stack<TreeNode*> stack;
    long long inorder=(long long)INT_MIN -1;

    while(!stack.empty()||root!=nullptr){
        while(root!=nullptr){
            stack.push(root);
            root =root->left;
        }
        root =stack.top();
        stack.pop();
        if(root->val <=inorder){
            return false;
        }
        inorder=root->val;
        root=root->right;
    }
    return true;

}


#endif //ALGORITHM_ISVALIDBST_H
