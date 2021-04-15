//
// Created by g fish on 2021/4/10.
//

#ifndef ALGORITHM_MEETINGNODE_H
#define ALGORITHM_MEETINGNODE_H
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
};
// 判断链表是否有环及环节点入口
ListNode* MeetingNode(ListNode *head) {
    if(head== nullptr) return nullptr;
    ListNode* pSlow=head->next;
    if(pSlow== nullptr){
        return nullptr;
    }
    ListNode *pFast=pSlow->next;
    while(pSlow!=nullptr&&pFast!= nullptr){
        if(pFast==pSlow){
            return pSlow;
        }
        pSlow=pSlow->next;
        pFast=pFast->next;
        if(pFast!= nullptr){
            pFast=pFast->next;
        }
    }
    return nullptr;
}
ListNode *EntryNodeLoop(ListNode *pHead){
    ListNode *meetingNode =MeetingNode(pHead);
    if(meetingNode== nullptr) return nullptr;

    int nodeLoop=1;
    ListNode *pNode=meetingNode;
    while(pNode->next!=meetingNode){
        pNode=pNode->next;
        nodeLoop++;
    }

    pNode=pHead;
    for(int i=0;i<nodeLoop;i++){
        pNode=pNode->next;
    }
    ListNode *pNode1=pHead;
    while(pNode1!=pNode){
        pNode1=pNode1->next;
        pNode=pNode->next;
    }
    return pNode;
}
#endif //ALGORITHM_MEETINGNODE_H
