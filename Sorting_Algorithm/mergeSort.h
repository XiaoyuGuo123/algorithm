//
// Created by g fish on 2021/4/17.
//
#include "vector"
#ifndef ALGORITHM_MERGESORT_H
#define ALGORITHM_MERGESORT_H

//归并排序,关键在于构造一个数组 然后merge，所以这个 merge函数是关键.归并时，需要保证子数组是有序的
void merge(vector<int> &arr,int start,int mid,int end){
    int* tmp= new int[end-start+1];
    int left=start;
    int right=mid+1;
    int tmpIndex=0;
    while(left<=mid && right <=end){
        if(arr[left]<arr[right]){
            tmp[tmpIndex++]=arr[left++];
        }else{
            tmp[tmpIndex++]=arr[right++];
        }
    }
    while(left<=mid){
        tmp[tmpIndex++]=arr[left++];
    }
    while(right<=end){
        tmp[tmpIndex++]=arr[right++];
    }

    for(int i=0;i<end-start+1;i++) {
        arr[start+i]=tmp[i];
    }
}
void mySortCore(vector<int> &arr,int start,int end){
    if(start>end) return;
    int mid=start+((end -start) >>1);
    mySortCore(arr,start,mid);
    mySortCore(arr,mid+1,end);
    merge(arr,start,mid,end);
}

vector<int> mySort(vector<int>& arr){
    mySortCore(arr,0,arr.size()-1);
    return arr;
}

#endif //ALGORITHM_MERGESORT_H
