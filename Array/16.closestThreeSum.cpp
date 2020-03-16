#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

/*
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。
返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int closeSum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; ++i) {
            int r = nums.size() - 1, l = i + 1;
            
            while (l < r) { 
                int threeSum = nums[l] + nums[i] + nums[r];
                if (abs(closeSum - target) > abs(threeSum - target)) {
                    closeSum = threeSum;
                }
                if (threeSum > target)      //错误的使用closeSum与target比较，导致只能找出第一轮的最优值
                    --r;
                else if (threeSum < target)
                    ++l;
                else
                    return target;
            }
        }
        return closeSum;
    }
};



int main() {
    vector<int> nums{ 1,2,4,8,16,32,64,128};
    int target = 82;
    Solution sol;
    int ans = sol.threeSumClosest(nums, target);
    cout << ans << endl;
	return 0;
}


/*
2020.03.04
执行用时 :
4 ms, 在所有 C++ 提交中击败了99.46%的用户
内存消耗 :
12.2 MB, 在所有 C++ 提交中击败了5.57%的用户
*/
