#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/**
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res_final;
        sort(nums.begin(), nums.end());
        if (nums.size() < 3 || nums[0] > 0 || nums[nums.size() - 1] < 0) return res_final;

        for (size_t i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int target = 0 - nums[i];
            int k = i + 1;
            int m = nums.size() - 1;
            while (k < m) {
                if (nums[k] > target) break;
                if ((k > i + 1 && nums[k] == nums[k - 1]) || nums[k] + nums[m] < target) {
                    ++k;
                }
                else if ((m < nums.size() - 1 && nums[m] == nums[m + 1]) || nums[k] + nums[m] > target) {
                    --m;
                }
                else {
                    vector<int> res;
                    res.push_back(nums[i]);
                    res.push_back(nums[k]);
                    res.push_back(nums[m]);
                    res_final.push_back(res);
                    ++k;
                }
            }
        }
        return res_final;
    }
};

/*
三数之和可以解构成在二数之和问题的基础上，将target值变成变化的值。对数组进行遍历，每一个元素的值就是target的取值。
过程中的小技巧：

为保证不重复，首先对数组进行排序，但不可去重。当target取值相同时，直接跳过即可，这是保证不重复需要注意的其中一点。
另一点是在寻找两数之和满足target值时，若遇到相同元素（相同元素一定相邻），可直接跳过。
用map结构求满足条件的两数时，时间复杂度是O(NlgN);用hash_map时，时间负责度是O(N);用双指针的时间复杂度也是O(N).
三数之和即在二数的基础上再乘N的复杂度。本人尝试过，若用map结构解该题会报超时。
用双指针是相对合适的解法，原因是双指针遍历时，可以结合先剪枝策略，从而降低平均耗时。
先剪枝策略：前面的指针所访问的元素大于target时，可提前结束。
过程中的注意事项：

边界判断：数组长度不得小于3
第一个元素大于0或最后一个元素小于0时，直接结束，返回空数组
*/
int main() {
    vector<int> nums = { -4, -2,  -1, -1, 0, 2, 3 };
    //vector<int> nums = { -1, 0, 1, 2, -1, -4 };
    Solution sol;
    vector<vector<int> > ans = sol.threeSum(nums);
   
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << ans[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}

/**
2020.01.08中等难度
一下午加晚上没有解决重复解的问题，且未用好双指针，在评论区找到的答案
执行用时 :
112 ms, 在所有 C++ 提交中击败了95.98%的用户
内存消耗 :
14.6 MB, 在所有 C++ 提交中击败了90.08%的用户
*/