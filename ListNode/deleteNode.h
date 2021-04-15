//
// Created by g fish on 2021/4/15.
//
#include "meetingNode.h"
#ifndef ALGORITHM_DELETENODE_H
#define ALGORITHM_DELETENODE_H
//o(1) 时间内删除链表节点

void DeleteList(ListNode *pHead,ListNode*pToBeDeleted){
    if(pHead== nullptr||pToBeDeleted== nullptr){
        return ;
    }

    //要删除的节点不是尾节点
    if(pToBeDeleted!= nullptr)
    {
        ListNode *pNext=pToBeDeleted->next;
        pToBeDeleted->val=pNext->val;
        pToBeDeleted->next=pNext->next;
        delete pNext;
        pNext= nullptr;
    }
    else if(pHead==pToBeDeleted)
    {
        //要删除的是头节点
        delete pToBeDeleted;
        pToBeDeleted= nullptr;
        pHead= nullptr;
    }
    else  //有多个节点，要删除的是尾节点
    {
        ListNode *pNode=pHead;
        while(pNode->next!=pToBeDeleted){
            pNode=pNode->next;
        }
        pNode->next= nullptr;
        delete pToBeDeleted;
        pToBeDeleted= nullptr;
    }
}

#endif //ALGORITHM_DELETENODE_H
