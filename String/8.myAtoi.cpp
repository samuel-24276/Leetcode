#include<iostream>
#include<string>
#include<cmath>

using namespace std;

/*
请你来实现一个 atoi 函数，使其能将字符串转换成整数。

首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。
当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，
作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。
该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该
造成影响。
注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，
则你的函数不需要进行转换。
在任何情况下，若函数不能进行有效的转换时，请返回 0。

说明：
假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231,  231 − 1]。
如果数值超过这个范围，请返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。

示例 1:

输入: "42"
输出: 42
示例 2:

输入: "   -42"
输出: -42
解释: 第一个非空白字符为 '-', 它是一个负号。
     我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
示例 3:

输入: "4193 with words"
输出: 4193
解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。
示例 4:

输入: "words and 987"
输出: 0
解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
     因此无法执行有效的转换。
示例 5:

输入: "-91283472332"
输出: -2147483648
解释: 数字 "-91283472332" 超过 32 位有符号整数范围。
     因此返回 INT_MIN (−231) 。
*/

class Solution {
public:
    int myAtoi(string str) {
        int size = str.size();
        int flag = 0;
        int res = 0;
        for (int i = 0; i < size; ++i) {          
            if (str[i] >= '0' && str[i] <= '9') {
                //cout << "int" << endl;                
                if (res > INT_MAX / 10 || (res == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10)) {                    
                    if(flag==1 || flag==0)  //若数字前仅出现一次+或0次+
                        return INT_MAX;
                    if(flag==-1)            //若数字前出现一次-
                        return INT_MIN;
                }
                res = res * 10 + int(str[i] - '0');
                if (i < size - 1 && (str[i + 1] < '0' || str[i + 1]>'9')) //提前判断下一位         
                    break;
            }
            else if (str[i] == '+' || str[i] == '-') {
                //cout << "symbol" << endl;
                //若前面出现过一次符号，这次又是符号，直接返回0
                //若符号后字符不是数字，直接返回0
                if (flag || str[i + 1] < '0' || str[i + 1]>'9')       
                    return 0;
                if (str[i] == '-')                     
                    flag = -1;                   
                else                   
                    flag = 1;                                        
            }
            else if (str[i] == ' ') {
                //cout << "空格" << endl;
                continue;
            }                
            else
                return 0;
        }
        if (flag==-1)
            res = -res;
        return res;
    }
};




int main() {
    string s = "  - 2147483647df  ";
    Solution sol;
    cout << sol.myAtoi(s) << endl;
	return 0;
}

/*
难度：中等--并不难，但条件多，易忽略
2020.03.21
执行用时 :
4 ms, 在所有 C++ 提交中击败了87.27%的用户
内存消耗 :
7.7 MB, 在所有 C++ 提交中击败了100.00%的用户
*/