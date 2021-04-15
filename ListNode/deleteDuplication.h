//
// Created by g fish on 2021/4/15.
//

#ifndef ALGORITHM_DELETEDUPLICATION_H
#define ALGORITHM_DELETEDUPLICATION_H

struct ListNode{
    int val;
    ListNode* next;
};

ListNode *DeleteDuplication(ListNode *pHead){
    if(pHead== nullptr) return nullptr;

    ListNode *pPreNode= nullptr;
    ListNode *pNode=pHead;
    while(pNode!= nullptr){
        ListNode *pNext=pNode->next;
        bool needDelete=false;
        if(pNext!= nullptr &&pNext->val==pNode->val){
            needDelete= true;
        }
        if(!needDelete){
            pPreNode=pNode;
            pNode=pNode->next;
        }
        else{
            int value=pNode->val;
            ListNode *pToBeDel=pNode;
            while(pToBeDel!= nullptr &&pToBeDel->val==value){
                pNext= pToBeDel->next;
                delete pToBeDel;
                pToBeDel= nullptr;
                pToBeDel=pNext;
            }
            if(pPreNode== nullptr){
                pHead=pNext;
            }else{
                pPreNode->next=pNext;
            }
            pNode=pNext;
        }
    }
    return pHead;
}

#endif //ALGORITHM_DELETEDUPLICATION_H
