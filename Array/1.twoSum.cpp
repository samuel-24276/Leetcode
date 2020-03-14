#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/***
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int size = nums.size();
        int sum;
        vector<int> val;
        for (int i = 0; i < size - 1; ++i)
        {
            for (int j = i + 1; j < size; ++j)
            {
                sum = nums[i] + nums[j];
                if (sum == target)
                {
                    val.push_back(i);
                    val.push_back(j);
                }
            }
        }
        return val;
    }
};


int main()
{
    vector<int> nums = { 3,2,4};
    int target = 6;
    Solution sol;
    vector<int> val = sol.twoSum(nums, target);
    cout << val[0] << endl << val[1] << endl;
    return 0;
}
/*
简单难度
2020.01.04
局部变量sum，需要多次申请其内存，耗费时间
执行用时 :
468 ms, 在所有 C++ 提交中击败了6.12%的用户
内存消耗 :
10.3 MB, 在所有 C++ 提交中击败了13.34%的用户

全局变量sum
执行用时 ：
432 ms, 在所有 C++ 提交中击败了9.38%的用户
内存消耗 :
10.8 MB, 在所有 C++ 提交中击败了5.02%的用户
*/
