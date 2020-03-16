#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

/*
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，
使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：
答案中不可以包含重复的四元组。

示例：
给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/



class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans; 
        if (nums.size() < 4)
            return ans;
        int i, j, l, r,_size=nums.size();   //把多次调用的nums.size()函数设为常量
        for (i = 0; i < _size - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;  //确保Nums[i]改变了
            for (j = i + 1; j < _size - 2; j++) {
                if (j > i+1 && nums[j] == nums[j - 1]) continue;  //确保Nums[j]改变了，**不是j>0**
                l = j + 1 , r = _size - 1;
                while(l<r){                    
                    if (nums[i] + nums[j] + nums[l] + nums[r] < target) {
                        l++;
                    }
                    else if (nums[i] + nums[j] + nums[l] + nums[r] > target) {
                        r--;
                    }
                    else {                      
                        ans.push_back({ nums[i], nums[j], nums[l],nums[r] });
                        while (l < r && nums[l+1] == nums[l])
                            l++;
                        while (l < r && nums[r-1] == nums[r])
                            r--;
                        l++;
                        r--;
                    }
                }                    
            }
        }       
        return ans;
    }
};

/*
未把size()函数常量化之前
执行用时 :
80 ms, 在所有 C++ 提交中击败了21.69%的用户
内存消耗 :
14.5 MB, 在所有 C++ 提交中击败了5.04%的用户
*/

/*
把size()函数常量化之后
执行用时:
44 ms, 在所有 C++ 提交中击败了67.57 %的用户
内存消耗 :
14.8 MB, 在所有 C++ 提交中击败了5.04 %的用户*/
int main() {
    vector<int> nums = { -3,-2,-1,0,0,1,2,3};
    int target = 0;
    vector<vector<int> > ans;
    Solution sol;
    ans = sol.fourSum(nums, target);
    for (auto val : ans) {
        for (int i = 0; i < 4; ++i) {
            cout << val[i] << "\t";
        }
        cout << endl;
    }
	return 0;
}

/*
2020.03.05
2020.03.10看了题解后解决
*/