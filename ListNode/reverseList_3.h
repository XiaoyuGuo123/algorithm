//
// Created by g fish on 2021/4/14.
//
#include "meetingNode.h"
#ifndef ALGORITHM_REVERSELIST_3_H
#define ALGORITHM_REVERSELIST_3_H
//反转部分链表，需要记录 start,end,startPre,endNext 节点
//这个算法，找到开始的前一个节点，那就找到了开始，找到结束的节点，就找到了结束的下一个节点
ListNode *ReverseListNodeFromTo(ListNode*pHead,int from, int to){
    int len=0;
    ListNode *cur=head;
    ListNode *startPre= nullptr;
    ListNode *end= nullptr;
    while(cur!= nullptr){
        len++;
        if(len==from-1){
            startPre=cur;
        }
        if(len==to){
            end=cur;
        }
        cur=cur->next;
    }

    //考虑from 是1的情况
    ListNode *start= (startPre== nullptr ?pHead:startPre->next);
    ListNode *endNext=end->next;

    cur=start;
    ListNode *pre= nullptr;
    ListNode *pNext= nullptr;
    while(cur!=endNext){
        pNext=cur->next;
        cur->next=pre;
        pre=cur;
        cur=pNext;
    }

    //如果是从头节点开始反转
    if(startPre!= nullptr){
        startPre->next=pre;
    }else{
        pHead=pre;
    }
    start->next=endNext;

    return pHead;
}


#endif //ALGORITHM_REVERSELIST_3_H
