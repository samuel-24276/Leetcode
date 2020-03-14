#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

/**
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) .在坐标内画 n 条垂直线，垂直线 i 的两个端点
分别为 (i, ai) 和 (i, 0)。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水.
图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7].在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49.
说明：你不能倾斜容器，且 n 的值至少为 2.

*/


/*
class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int width = 0, max=0, cap=0;
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                width = height[i] < height[j] ? height[i] : height[j]; 
                cap = width * (j - i);
                if (cap > max) {
                    max = cap;
                }
            }
        }
        return max;
    }
};*/

/*暴力破解法的优化--倒序遍历
首先我们遍历到[0, n], 有两种可能:
第一种可能: 0的高度小于等于n的高度。 这种情况下我们无需再遍历[0, n-1], [0, n-2] ...[0, 1]了，
因为后面坐标对应的矩形，首先在宽度上在逐渐减小，高度上又不能比0的大（高度取决于两边最小的高度），
所以后面坐标形成的矩形面积不会比[0,n]大了， 即当i=0的坐标，都可以不用遍历了，这其实是削减了i的遍历范围， 
从刚开始的0<=i <= n-1 变成了 1<= i <= n-1， 这本质上就是双指针算法里面的左指针右移。

第二种可能：0的高度大于等于n的高度。这种情况下我们无需再遍历 [1, n], [2, n], [3, n] ... [0,n]了， 原因同上， 
宽度在逐渐减小， 高度不会大于n对应的高度。即当j=n的坐标都不会遍历了，这其实是削减了j的遍历范围, 
从刚开始的1 <=j <= n 变成了 1<= i <= n-1,这本质上就是双指针算法里面的右指针左移。
*/

/*
class Solution {
public:
    int maxArea(vector<int>& height) {             
        int max = 0, area = 0, len = height.size();
        int st = len-1;        
        for (int i = 0; i < len; ++i) {         //i,j分别为左右指针
            for (int j = st; j > i; --j) {  
                if (height[i] <= height[j]) {
                //左i小于右j，则以左i为高，宽j-i只会越来越小，高i不变，此时的面积为此轮j循环最大值
                    area = (j - i) * height[i];
                    j = i + 1;      //--j后j==i跳出j循环
                }
                else {
                    //左i大于右j，以右j为高，i在此轮循环中固定，宽j-i只会越来越小，高i/j不确定，需要遍历i/j
                    area = (j - i) * height[j];
                    st = j; //此语句若省略，复杂度会增高，变为i简化,j暴力破解版本
                }
                max = max < area ? area : max;
            }
            
        }
        return max;
    }
};
*/ 


/*
如果我们试图将指向较长线段的指针向内侧移动，矩形区域的面积将受限于较短的线段而不会获得任何增加。但是，
在同样的条件下，移动指向较短线段的指针尽管造成了矩形宽度的减小，但却可能会有助于面积的增大。因为移动较
短线段的指针会得到一条相对较长的线段，这可以克服由宽度减小而引起的面积减小。
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0, area = 0, len = height.size();
        int i = 0, j = len - 1;
        while (i < j) {
            if (height[i] <= height[j]) {
                area = (j - i) * height[i];
                ++i;
            }
            else {
                area = (j - i) * height[j];
                --j;
            }
            max = max < area ? area : max;
        }
        return max;
    }
};

int main() {
    vector<int> height = { 1,8,6,2,5,4,8,3,7 };
    Solution sol;
    cout <<"MAXAREA:"<< sol.maxArea(height)<< endl;
    return 0;
}

/**中等难度，需要贪心思想
2020.01.08暴力破解--类似排列组合
执行用时 :
1860 ms, 在所有 C++ 提交中击败了10.96%的用户
内存消耗 :
9.7 MB, 在所有 C++ 提交中击败了86.55%的用户

暴力破解优化--无st = j;版
执行用时 :
604 ms, 在所有 C++ 提交中击败了23.73%的用户
内存消耗 :
15.3 MB, 在所有 C++ 提交中击败了5.15%的用户

暴力破解优化--倒序遍历--去if用三目运算符，把左右指针i,j变为局部变量
执行用时 :
16 ms, 在所有 C++ 提交中击败了90.86%的用户
内存消耗 :
9.9 MB, 在所有 C++ 提交中击败了61.58%的用户

2020.03.13
暴力破解优化-双指针版
执行用时 :
20 ms, 在所有 C++ 提交中击败了63.51%的用户
内存消耗 :
15.3 MB, 在所有 C++ 提交中击败了5.15%的用户

*/