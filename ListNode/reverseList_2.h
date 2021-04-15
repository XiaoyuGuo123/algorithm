//
// Created by g fish on 2021/4/14.
//
#include "meetingNode.h"
#ifndef ALGORITHM_REVERSELIST_2_H
#define ALGORITHM_REVERSELIST_2_H
//反转链表后n个节点
ListNode *ReversebehindKthList(ListNode *pHead,int n){
    if(pHead== nullptr) return nullptr;
    ListNode* pFast=pHead;
    ListNode* pSlow=pHead;
    for(int i=0;i<n;i++){
        pFast=pFast->next;
    }
    while(pFast->next!= nullptr){
        pFast=pFast->next;
        pSlow=pSlow->next;
    }
    ListNode *Cur=pSlow->next;
    ListNode *pPre= nullptr;
    ListNode *pNext= nullptr;
    while(Cur!= nullptr){
        pNext=Cur->next;
        Cur->next=pPre;
        pPre=Cur;
        Cur=pNext;
    }
    pSlow->next=pPre;
}

#endif //ALGORITHM_REVERSELIST_2_H
