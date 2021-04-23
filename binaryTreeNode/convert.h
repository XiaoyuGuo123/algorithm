//
// Created by g fish on 2021/4/21.
//

#ifndef ALGORITHM_CONVERT_H
#define ALGORITHM_CONVERT_H
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};
//二叉搜索树与双向链表
/*输入一颗二叉搜索树，将该二叉搜索树转换称一个排序的双向链表*/
/*
 * 二叉搜索树的中序遍历是递增的
 * 先中序遍历
 * 双向链表：树的节点的右指针指向下一个节点；树的节点的左指针指向前一个节点
 * */
TreeNode *head = nullptr;
TreeNode *end = nullptr;

TreeNode* Convert(TreeNode *pRoot){
    CovertNode(pRoot);
    return head;
}

void CovertNode(TreeNode *pNode){
    if(pNode== nullptr) return;

    if(cur->left!= nullptr){
        CovertNode(pNode->left);
    }
    if(end== nullptr){
        head= pNode;
        end= pNode;
    }else{
        end->right=pNode;
        pNode->left=end;
        end=pNode;
    }
    if(cur->right!= nullptr){
        CovertNode(cur->right);
    }
}

#endif //ALGORITHM_CONVERT_H
