#if __has_include("util.hpp")
#include "util.hpp"
#endif

class Solution {
public:
  vector<int> perfect_permutation(int n) {
    vector<int> ans={1};
    // 请在这里完成你的代码
      while (ans.size() < n)
      {
          vector<int> temp;
          for (auto i : ans)
          {
              if (i*2 - 1 <= n)
              {
                temp.push_back(i*2 - 1);
              } 
          }
          for (auto i : ans)
          {
              if (i*2 <= n)
              {
                temp.push_back(i*2);
              } 
          }
          ans = temp;
      }

    return ans;
  }
};