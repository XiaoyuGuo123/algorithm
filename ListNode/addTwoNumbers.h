//
// Created by gfish on 2021/6/6.
//

#ifndef ALGORITHM_ADDTWONUMBERS_H
#define ALGORITHM_ADDTWONUMBERS_H
struct ListNode{
    ListNode* next;
    int val;
};

//两个链表相加
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    return addTwoNumbersCore(l1,l2,0);
}

ListNode* addTwoNumbersCore(ListNode*l1,ListNode*l2,int carry){
    if(!l1 &&!l2 &&carry==0){
        return nullptr;
    }

    int val=carry+(l1 ?l1->val:0)+(l2?l2->val:0);
    auto res=new ListNode(val%10);
    res->next=addTwoNumbersCore((l1?l1->next:nullptr),(l2?l2->next:nullptr),val/10);
    return res;
}

#endif //ALGORITHM_ADDTWONUMBERS_H
