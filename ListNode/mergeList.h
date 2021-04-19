//
// Created by g fish on 2021/4/19.
//
#include "meetingNode.h"
#ifndef ALGORITHM_MERGELIST_H
#define ALGORITHM_MERGELIST_H
//合并两个有序链表
ListNode* merge(ListNode* pHead1,ListNode* pHead2){
    if(pHead1== nullptr){
        return pHead2;
    }else if(pHead2== nullptr){
        return pHead1;
    }
    ListNode *mergeHead= nullptr;
    if(pHead1->val <pHead2->val){
        mergeHead=pHead1;
        mergeHead->next=merge(pHead1->next,pHead2);
    }else{
        mergeHead=pHead2;
        mergeHead->next=merge(pHead1,pHead2->next);
    }
    return mergeHead;
}

#endif //ALGORITHM_MERGELIST_H
