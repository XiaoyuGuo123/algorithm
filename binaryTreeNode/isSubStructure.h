//
// Created by g fish on 2021/5/16.
//

#ifndef ALGORITHM_ISSUBSTRUCTURE_H
#define ALGORITHM_ISSUBSTRUCTURE_H
//树的子结构，B是否是A的子结构
//先判断根节点是否相等，然后判断左右节点是否相等
struct TreeNode{
    int     val;
    TreeNode *left;
    TreeNode *right;
};

bool isSubStructure(TreeNode* A, TreeNode* B) {
    bool result=false;

    if(A!=nullptr&&B!=nullptr){
        if(A->val==B->val){
            result=DoesTree1HaveTree2(A,B);
        }

        if(!result){
            result=isSubStructure(A->left,B);
        }
        if(!result){
            result=isSubStructure(A->right,B);
        }
    }
    return result;
}

bool DoesTree1HaveTree2(TreeNode* A, TreeNode *B){
    if(B==nullptr){
        return true;
    }
    if(A==nullptr){
        return false;
    }

    if(A->val!=B->val){
        return false;
    }
    return DoesTree1HaveTree2(A->left,B->left)&&DoesTree1HaveTree2(A->right,B->right);

}


#endif //ALGORITHM_ISSUBSTRUCTURE_H
