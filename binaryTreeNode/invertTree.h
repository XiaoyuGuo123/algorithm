//
// Created by gfish on 2021/7/24.
//

#ifndef ALGORITHM_INVERTTREE_H
#define ALGORITHM_INVERTTREE_H
struct TreeNode{
    TreeNode* right;
    TreeNode* left;
    int val;
};
TreeNode* invertTree(TreeNode* root) {
    if(root==nullptr){
        return nullptr;
    }
    TreeNode *left=invertTree(root->left);
    TreeNode *right=invertTree(root->right);
    root->left=right;
    root->right=left;
    return root;
}

#endif //ALGORITHM_INVERTTREE_H
