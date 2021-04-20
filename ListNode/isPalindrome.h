//
// Created by g fish on 2021/4/20.
//
#include "meetingNode.h"
#include "reverseList.h"
#ifndef ALGORITHM_ISPALINDROME_H
#define ALGORITHM_ISPALINDROME_H
//判断链表是否是回文
//链表系列参考知乎这个总结，感觉作者总结的不错：https://zhuanlan.zhihu.com/p/96724460
bool isPalindrome(ListNode *pHead){
    if(phead== nullptr||pHead->next== nullptr) return true;

    ListNode *fast=pHead;
    ListNode *slow=pHead;
    while(fast->next!= nullptr &&fast->next->next!= nullptr){
        fast=fast->next->next;
        slow=slow->next;
    }

    ListNode *rHead=ReverseList(slow->next);
    ListNode *cur=rHead;

    bool result= true;

    while(cur!= nullptr){
        if(pHead->val!=cur->val){
            result= false;
            break;
        }
        cur=cur->next;
        pHead=pHead->next;
    }
    slow->next=ReverseList(rHead);
    return  result;
}

#endif //ALGORITHM_ISPALINDROME_H
