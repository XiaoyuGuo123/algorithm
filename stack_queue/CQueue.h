//
// Created by g fish on 2021/4/13.
//
#include "stack"
#ifndef ALGORITHM_CQUEUE_H
#define ALGORITHM_CQUEUE_H

class CQueue{
public:
    void appendTail(int value);
    int deleteHead();
    CQueue(){};

private:
    stack<int> s1;
    stack<int> s2;
};

void CQueue::appendTail(int value) {
    s1.push(value);
}

int CQueue::deleteHead() {
    if(s2.empty()){
        while (!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
    if (s2.empty()){
        return -1;
    }else{
        int deleteItem=s2.top();
        s2.pop();
        return deleteItem;
    }
}


#endif //ALGORITHM_CQUEUE_H
