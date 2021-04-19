//
// Created by g fish on 2021/4/19.
//
#include "meetingNode.h"
#ifndef ALGORITHM_FINDKTHTOTAIL_H
#define ALGORITHM_FINDKTHTOTAIL_H
//链表中倒数第k个节点
ListNode *FindKthTotail(ListNode *pHead,int k){
    if(pHead== nullptr ||k=0) return nullptr;
    ListNode *pAHead=pHead;
    ListNode *pBehind= nullptr;
    for(int i=0;i<k-1;i++){
        if(pAHead->next!= nullptr){
            pAHead=pAHead->next;
        }else{
            return nullptr;
        }
    }
    pBehind=pHead;
    while (pAHead->next!= nullptr){
        pAHead=pAHead->next;
        pBehind=pBehind->next;
    }
    return pBehind;
}


#endif //ALGORITHM_FINDKTHTOTAIL_H
