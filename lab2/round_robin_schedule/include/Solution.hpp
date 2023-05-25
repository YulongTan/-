#if __has_include("util.hpp")
#include "util.hpp"
#endif

class Solution {
public:
  void schedule(vector<vector<int>> &ans,int n)
  {
    if(n==1)
    {
      ans[0][0]=1;
      return;
    }
    schedule(ans,n/2);
    chart(ans,n);
  }

  void chart(vector<vector<int>> &ans,int n)
  {
    int m,i,j;
    m=n/2;
    for(i=0;i<m;i++)
    {
      for(j=0;j<m;j++)
      {
        ans[i][j+m]=ans[i][j]+m;
        ans[i+m][j]=ans[i][j]+m;
        ans[i+m][j+m]=ans[i][j];
      }
    }
  }

  vector<vector<int>> round_robin_schedule(int n) {
    // 如此构造一个二维数组（ nxn 矩阵）
    // ans[i][j]表示矩阵的第i行第j列
    vector<vector<int> > ans;
    for(int i=0; i<n; i++) {
      ans.push_back(vector<int>(n, 0));
    }
    // 请在这里完成你的代码
    schedule(ans,n);
    return ans;
  }

};
