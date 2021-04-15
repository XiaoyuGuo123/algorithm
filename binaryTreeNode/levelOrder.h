//
// Created by g fish on 2021/4/10.
//
#include "vector"
#include "treeDepth.h"
#include "queue"
#ifndef ALGORITHM_LEVELORDER_H
#define ALGORITHM_LEVELORDER_H

// 层序遍历
vector<vector<int>> levelOrder(BinaryTreeNode *pRoot){
    vector<vector<int>> res;
    if(pRoot==nullptr) return res;
    queue<BinaryTreeNode *> qu;
    qu.push(pRoot);
    while(!qu.empty()){
        int size=qu.size();
        vector<int> vc;
        for(int i=0;i<size;i++){
            BinaryTreeNode *node =qu.front();
            qu.pop();
            vc.push_back(node->val);
            if(node->left) qu.push(node->left);
            if(node->right) qu.push(node->right);
        }
        if(vc.size()>0) res.push_back(vc);
    }
    return res;
}


#endif //ALGORITHM_LEVELORDER_H
