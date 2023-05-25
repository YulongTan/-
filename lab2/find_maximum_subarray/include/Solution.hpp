#if __has_include("util.hpp")
#include "util.hpp"
#endif

/*
提示：
int范围：
  无穷小可以用 INT_MIN 表示
  无穷大可以用 INT_MAX 表示
long long 范围：
  无穷小可以用 LLONG_MIN 表示
  无穷大可以用 LLONG_MAX 表示
*/

class Solution {
public:
  int find_maximum_crossing_subarray(vector<int> &A, int low, int mid, int high) {
    // 请在这里完成你的代码
    int left_sum=INT_MIN;
    int sum=0;
    int max_left=0;
    for(int i=mid;i>=low;i--)
    {
      sum=sum+A[i];
      if(sum>left_sum)
      {
        left_sum=sum;
        max_left=i;
      }
    }
    int right_sum=INT_MIN;
    sum=0;
    int max_right=0;
    for(int j=mid+1;j<=high;j++)
    {
      sum=sum+A[j];
      if(sum>right_sum)
      {
        right_sum=sum;
        max_right=j;
      }
    }
    return (max_left,max_right,left_sum+right_sum);
  }
  int find_maximum_subarray(vector<int> &A, int low, int high) {
    // 请在这里完成你的代码
    int mid;
    int left_low,left_high,left_sum;
    int right_low,right_high,right_sum;
    int cross_low,cross_high,cross_sum;
    if(high==low)
    {
      return(low,high,A[low]);
    }
    else
    {
      mid=((low+high)/2);
      (left_low,left_high,left_sum)=find_maximum_subarray(A,low,mid);
      (right_low,right_high,right_sum)=find_maximum_subarray(A,mid+1,high);
      (cross_low,cross_high,cross_sum)=find_maximum_crossing_subarray(A,low,mid,high);
      if((left_sum>=right_sum)&&(left_sum>=cross_sum))
      {
        return(left_low,left_high,left_sum);
      }
      else if((right_sum>=left_sum)&&(right_sum>=cross_sum))
      {
        return(right_low,right_high,right_sum);
      }
      else return(cross_low,cross_high,cross_sum);
    }
  }
  int find_maximum_subarray(vector<int> &A) {
    return find_maximum_subarray(A, 0, A.size() - 1);
  }
};
