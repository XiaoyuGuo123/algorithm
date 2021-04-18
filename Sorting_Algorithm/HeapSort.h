//
// Created by g fish on 2021/4/11.
//

#include <vector>
#include<stdio.h>



#ifndef ALGORITHM_HEAPSORT_H
#define ALGORITHM_HEAPSORT_H
//堆排序

//建立大堆，实现从小到大排序

void swap(int &i,int &j){
    int tmp=i;
    i=j;
    j=tmp;
}

//i 表示父节点，n代表arr的长度
void maxHeapIfy(vector &arr,int i,int n){
    int l=2*i+1;  //左孩子
    int r=2*i+2;  //右孩子
    int largest=i; //暂认为最大的值是父节点
    if(l<n && arr[l]>arr[largest]){
        largest=l;
    }
    if(r<n &&arr[r] >arr[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        maxHeapIfy(arr,largest,n);
    }
}

void buildMaxHeap(vector &arr){
    int n=arr.size();
    for(int i=n/2-1;i>=0;i--){
        maxHeapIfy(arr,i,n);
    }
}


vector<int> mySort(vector<int> &arr){
    //先建立堆
    buildMaxHeap(arr);
    //再调整堆
    int n=arr.size();
    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        maxHeapIfy(arr,0,i);
    }
    return arr;
}


#endif //ALGORITHM_HEAPSORT_H
