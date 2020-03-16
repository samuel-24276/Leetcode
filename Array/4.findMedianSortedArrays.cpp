#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/***
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int len = len1 + len2;
        int i=0, j=0;
        vector<int> nums;
        if (len1 && len2) {
            while (i < len1 && j < len2) {
                if (nums1[i] < nums2[j]) {
                    nums.push_back(nums1[i++]);
                }
                else
                    nums.push_back(nums2[j++]);
            }
        }
        while (i < len1)
            nums.push_back(nums1[i++]);
        while (j < len2)
            nums.push_back(nums2[j++]);
        if (len % 2 != 0)
            return nums[len / 2];
        else {
            double n = (double)(nums[len / 2 - 1] + nums[len / 2]) / 2;
            return n;
        }  
    }
};

int main()
{
    vector<int> nums1 = {1,6 };
    vector<int> nums2 = {  };
    Solution sol;
    double m = sol.findMedianSortedArrays(nums1, nums2);
    cout << "中位数为：" <<m<< endl;
	return 0;
}


/**
2020.01.07困难难度
执行用时 :
24 ms, 在所有 C++ 提交中击败了57.08%的用户
内存消耗 :
10.4 MB, 在所有 C++ 提交中击败了75.50%的用户

*/