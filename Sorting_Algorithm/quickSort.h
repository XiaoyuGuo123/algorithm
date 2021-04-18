//
// Created by g fish on 2021/4/17.
//
#include "vector"

#ifndef ALGORITHM_QUICKSORT_H
#define ALGORITHM_QUICKSORT_H
//快速排序
vector<int> mySort(vector<int>& arr){
    int start=0;
    int end=arr.size()-1;
    mySoreCore(arr,start,end);
    return arr;
}

void mySoreCore(vector<int>&arr,int start,int end){
    if(start<end){
        //分段位置下标
        int pivot=partition(arr,start,end);
        //d递归调用
        //左边排序
        mySoreCore(arr,start,pivot-1);
        //右边排序
        mySoreCore(arr,pivot,end);
    }
}

int partition(vector<int> &arr,int start,int end){
    int left=start;
    int right=end;
    //基准数据
    int pivotKey=arr[left];
    while(left<right){
        //因为默认基准是从左边开始，从右边开始比较
        //当尾指针大于基准时，向前移动右指针
        while(left<right &&arr[right]>=pivotKey)
            right--;
        //当找到比left的小时，赋值
        arr[left]=arr[right];
        //从左边开始找大的
        while(left<right && arr[left] <=pivotKey)
            left++;
        arr[right]=arr[left];
    }
    //left ==right 时，跳出循环，把基准换到正确的位置
    //把基准数据赋给正确位置
    arr[left]=pivotKey;
    return left;
}


#endif //ALGORITHM_QUICKSORT_H
