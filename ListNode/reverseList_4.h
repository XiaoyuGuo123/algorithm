//
// Created by g fish on 2021/4/14.
//
#include "meetingNode.h"
#include "reverseList.h"
#ifndef ALGORITHM_REVERSELIST_4_H
#define ALGORITHM_REVERSELIST_4_H
////k个为一组，分为子链表。pre记录子链表的头节点的前驱节点，end记录子链表尾节点
ListNode *ReverseKthListNode(ListNode *pHead,int k){
    ListNode *dummy=new ListNode(0);
    dummy->next=pHead;
    ListNode *pre=dummy;
    ListNode *end=dummy;
    while(end->next!= nullptr){
        for(int i=0;i<k &&end!= nullptr;i++){
            end=end->next;
        }
        if(end== nullptr){
            break;
        }
        ListNode *start=pre->next;
        ListNode *endNext=end->next;
        end->next= nullptr;

        pre->next=ReverseList(start);
        start->next=endNext;
        pre=start;
        end=start;
    }
    return dummy->next;
}

#endif //ALGORITHM_REVERSELIST_4_H
