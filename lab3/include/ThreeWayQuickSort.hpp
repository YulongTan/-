#pragma once
#include "MySort.hpp"
/*
该文件为三路快速排序（拓展实验）
*/

class ThreeWayQuickSort: public MySort {
public:
  void three_way_quick_sort(std::vector<int>& nums, int p, int q) {
    // 请在这里完成你的代码
    if (p < q) {
        int i = p, j = q;
        swap(nums[rand()%(q - p + 1) + p], nums[p]);
        int temp = nums[p];
        while (i < j) {
            while (i < j && nums[j] >= temp) {
                --j;
            }
            swap(nums[i], nums[j]);
            while (i < j && nums[i] <= temp) {
                ++i;
            }
            swap(nums[i], nums[j]);
        }
        three_way_quick_sort(nums, p, i - 1);
        three_way_quick_sort(nums, i + 1, q);
    }
  }
  void mysort(std::vector<int>& nums) {
    if(nums.size() == 0) return;
    three_way_quick_sort(nums, 0, nums.size() - 1);
  }
};