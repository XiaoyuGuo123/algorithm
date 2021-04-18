//
// Created by g fish on 2021/4/18.
//

#ifndef ALGORITHM_SEARCHLEFT_H
#define ALGORITHM_SEARCHLEFT_H
//寻找左边界
int searchLeft(int* nums, int target,int len) {
    int l = 0, r = len-1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return r;  // 一定会跳出while循环，此时l = r + 1;
}

#endif //ALGORITHM_SEARCHLEFT_H
