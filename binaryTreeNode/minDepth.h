//
// Created by gfish on 2021/5/23.
//

#ifndef ALGORITHM_MINDEPTH_H
#define ALGORITHM_MINDEPTH_H

/*
 * 给定一个二叉树，找出其最小深度。
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 */
struct TreeNode{
    TreeNode *left;
    TreeNode *right;
};
int INT_MAX=65535;
int minDepth(TreeNode *root){
    if(root== nullptr) return 0;
    if(root->left== nullptr &&root->right== nullptr){
        return 1;
    }
    int min_depth=INT_MAX;
    if(root->left!= nullptr){
        min_depth= min(minDepth(root->left),min_depth);
    }
    if(root->right!= nullptr){
        min_depth=min(minDepth(root->right),min_depth);
    }
    return min_depth+1;
}


#endif //ALGORITHM_MINDEPTH_H