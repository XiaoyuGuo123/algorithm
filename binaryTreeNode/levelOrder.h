//
// Created by g fish on 2021/4/10.
//
#include "vector"
#include "treeDepth.h"
#include "queue"
#ifndef ALGORITHM_LEVELORDER_H
#define ALGORITHM_LEVELORDER_H

// 层序遍历
//返回的是二维vector的形式
vector<vector<int>> levelOrder(TreeNode *pRoot){
    vector<vector<int>> res;
    if(pRoot==nullptr) return res;
    queue<TreeNode *> qu;
    qu.push(pRoot);
    while(!qu.empty()){
        int size=qu.size();
        vector<int> vc;
        for(int i=0;i<size;i++){
            TreeNode *node =qu.front();
            qu.pop();
            vc.push_back(node->val);
            if(node->left) qu.push(node->left);
            if(node->right) qu.push(node->right);
        }
        if(vc.size()>0) res.push_back(vc);
    }
    return res;
}

/*
 *  3
   / \
  9  20
    /  \
   15   7
   */

//[3,9,20,15,7] 返回为一维数组的形式
vector<int> levelOrder(TreeNode* root) {
    vector<int> res;
    if(root==nullptr) return res;
    queue<TreeNode*> qu;
    qu.push(root);
    while(!qu.empty()){
        TreeNode* node= qu.front();
        res.push_back(node->val);
        qu.pop();
        if(node->left!=nullptr){
            qu.push(node->left);
        }
        if(node->right!=nullptr){
            qu.push(node->right);
        }
    }
    return res;
}

//遍历结果为: 奇数层不反转，偶数层反转
//[
//  [3],
//  [20,9],
//  [15,7]
//]
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(root==nullptr) return res;
    queue<TreeNode *> qu;
    qu.push(root);
    while(!qu.empty()){
        int size=qu.size();
        vector<int> vc;
        for(int i=0;i<size;i++){
            TreeNode *node =qu.front();
            qu.pop();
            vc.push_back(node->val);

            if(node->left) qu.push(node->left);
            if(node->right) qu.push(node->right);
        }

        if(res.size()&1){
            reverse(vc.begin(),vc.end());
        }
        if(vc.size()>0) res.push_back(vc);
    }
    return res;
}

#endif //ALGORITHM_LEVELORDER_H
