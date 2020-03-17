#include<iostream>
#include<string>
#include<map>
using namespace std;

/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {  
        //复杂度O(n^2),解法：双指针滑动窗口
        //i为右边界，j为左边界
        int  size = s.size(), st = 0, i, j, max = 0;
        for (i = 0;i < size;++i) {
            //此处的for()循环类似三数之和的while()循环，以循环体外变量i的某种形式为初值
            for (j = st;j < i;++j) {
                if (s[j] == s[i]) {//字符串两端值相同，则无重复最长子串长度必定比其小
                    st = j + 1;
                    break;          //剪枝
                }
            }
            if (i - st + 1 > max)   //为防止特殊情况：串只有一个字符，不能用i-j
                max = i - st + 1;
        }
        return max;
    }   
};

int main() {
    string s = "a";
    Solution sol;
    cout << sol.lengthOfLongestSubstring(s) << endl;
	return 0;
}

/*
滑动窗口，即数学上枚举（暴力破解）的优化--若无剪枝，等同于暴力破解，可以把数组内所有元素均比较一遍
与11.Maxarea的倒序遍历有一定区别
int p = 0;
for (int k = 0; k < 10; ++k) {
    for (int m = p; m < k; ++m) {
        cout << m << " " << k << endl;
    }
}
*/
/*
2020.03.17看题解完成
3.最长无重复子串 难度：中等
双指针滑动窗口法
执行用时 :
12 ms, 在所有 C++ 提交中击败了80.18%的用户
内存消耗 :
8.4 MB, 在所有 C++ 提交中击败了100.00%的用户
*/