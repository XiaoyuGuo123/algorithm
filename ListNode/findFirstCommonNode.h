//
// Created by g fish on 2021/4/19.
//
#include "meetingNode.h"
#ifndef ALGORITHM_FINDFIRSTCOMMONNODE_H
#define ALGORITHM_FINDFIRSTCOMMONNODE_H
//获取链表的长度
int getListLength(ListNode *pHead){
    int len=0;
    ListNode *pNode=pHead;
    while(pNode!= nullptr){
        len++;
        pNode=pNode->next;
    }
    return len;
}
//两个链表的第一个公共节点
ListNode *FindFirstCommonNode(ListNode *pHead1,ListNode *pHead2){
    int len1=getListLength(pHead1);
    int len2=getListLength(pHead2);
    int diff=len1-len2;
    ListNode *pListHeadLong=pHead1;
    ListNode *pListHeadShort=pHead2;
    if(len2>len1){
        pListHeadLong=pHead2;
        pListHeadShort=pHead1;
        diff=len2-len1;
    }
    for(int i=0;i<diff;i++){
        pListHeadLong=pListHeadLong->next;
    }
    while((pListHeadLong!= nullptr)&&(pListHeadShort!= nullptr)&&(pListHeadShort==pListHeadLong)){
        pListHeadShort=pListHeadShort->next;
        pListHeadLong=pListHeadLong->next;
    }

    return pListHeadLong;
}
#endif //ALGORITHM_FINDFIRSTCOMMONNODE_H
