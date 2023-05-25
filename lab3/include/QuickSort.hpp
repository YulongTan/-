#pragma once
#include "MySort.hpp"
/*
该文件为快速排序
*/

class QuickSort: public MySort {
public:
  int partition(std::vector<int>& nums, int p, int q) {
    // 请在这里完成你的代码
    swap(nums[q],nums[rand()%(q-p+1)+p]);
    int pivot=nums[q];
    int i=p-1;
    int j=0;
    for(j=p;j<=q-1;j++)
    {
      if(nums[j]<=pivot)
      {
        i=i+1;
        swap(nums[i],nums[j]);
      }
    }
    swap(nums[i+1],nums[q]);
    return i+1;
  }
  void quick_sort(std::vector<int>& nums, int l, int r) {
    // 请在这里完成你的代码
    if(l<r)
    {
      int q=partition(nums,l,r);
      quick_sort(nums,l,q-1);
      quick_sort(nums,q+1,r);
    }
    else
    {
      return;
    }
  }
  void mysort(std::vector<int>& nums) {
    if(nums.size() == 0) return;
    quick_sort(nums, 0, nums.size() - 1);
  }
};