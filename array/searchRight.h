//
// Created by g fish on 2021/4/18.
//

#ifndef ALGORITHM_SEARCHRIGHT_H
#define ALGORITHM_SEARCHRIGHT_H
int searchRight(int *nums, int target,int len) {
    int l = 0, r = len-1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] > target) {
            r = mid - 1;  //如果是r = mid,则会陷入死循环
        } else {
            l = mid + 1;  //如果nums[mid] < target的话，说明要找的索引在右边，因此把l往mid往右挪一个
        }
    }
    return l;  // 一定会跳出while循环，此时l = r + 1;
}

#endif //ALGORITHM_SEARCHRIGHT_H
