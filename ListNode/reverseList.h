//
// Created by g fish on 2021/4/11.
//
#include "meetingNode.h"
#ifndef ALGORITHM_REVERSELIST_H
#define ALGORITHM_REVERSELIST_H
//链表反转
ListNode *ReverseList(*ListNode pHead){
    ListNode* pResHead=nullptr;
    ListNode* pNode=pHead;
    ListNode* pPrev=nullptr;
    while(pNode!=nullptr){
        ListNode* pNext=pNode->next;
        if(pNext==nullptr){
            pResHead=pNode;
        }
        pNode->next=pPrev;
        pPrev=pNode;
        pNode=pNext;
    }
    return pResHead;
}


#endif //ALGORITHM_REVERSELIST_H
