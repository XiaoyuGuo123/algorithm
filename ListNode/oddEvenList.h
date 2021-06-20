//
// Created by gfish on 2021/6/20.
//

#ifndef ALGORITHM_ODDEVENLIST_H
#define ALGORITHM_ODDEVENLIST_H

// 奇偶链表 先是奇数节点，再是偶数节点
/*示例1 */
//输入: 1->2->3->4->5->NULL
//输出: 1->3->5->2->4->NULL

/*示例2 */
//输入: 2->1->3->5->6->4->7->NULL
//输出: 2->3->6->7->1->5->4->NULL

struct ListNode{
    int val;
    ListNode *next;
};

ListNode* oddEvenList(ListNode* head) {
    if(head==nullptr){
        return head;
    }
    ListNode *evenHead= head->next;
    ListNode *odd=head;
    ListNode *even=evenHead;
    while(even!=nullptr &&even->next!=nullptr){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    odd->next=evenHead;
    return head;
}

#endif //ALGORITHM_ODDEVENLIST_H
