//
// Created by g fish on 2021/4/14.
//
#include "meetingNode.h"
#ifndef ALGORITHM_REVERSELIST_1_H
#define ALGORITHM_REVERSELIST_1_H
//反转链表 前n个节点
ListNode * ReversePreKthList( ListNode *pHead,int n){
    if(pHead== nullptr) return nullptr;
    ListNode *pNode=pHead;
    for(int i=0;i<n;i++){
        pNode=pNode->next;
    }
    ListNode *pPre= nullptr;
    ListNode *pNext;
    ListNode *cur=pHead;
    while(cur!=pNode){
        pNext=cur->next;
        cur->next=pPre;
        pPre=cur;
        cur=pNext;
    }
    pHead->next=pNode;
    return pPre;
}
#endif //ALGORITHM_REVERSELIST_1_H
