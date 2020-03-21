#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

/*
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

L   C   I   R
E T O E S I I G
E   D   H   N
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
示例 1:

输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"
示例 2:

输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:

L     D     R
E   O E   I I
E C   I H   N
T     S     G
*/

/*暴力破解法：按Z字形走一遍存进去，再正方形走一遍取出来
class Solution {
public:
    string convert(string s, int numRows) {
        int size = s.size();   
        if (size <= numRows || numRows==1)
            return s;
        char Matrix[1000][1000] = { 0 };
        int col = 0;
        for (int i = 0; i < size; ++col) { //col为列号，i为字符下标
            int pos = numRows - 1 - (col % (numRows - 1));
            for (int j = 0; j < numRows && i < size; ++j) {                 
                if (col % (numRows - 1) == 0) {     //满列的情况                    
                    Matrix[j][col]=s[i];
                    //cout <<"="<< Matrix[j][col] << endl;
                    ++i;
                }
                else {
                    Matrix[pos][col] = s[i];
                    ++i;
                    //cout << Matrix[pos][col] << endl;      
                    break;
                }                
            }
        }
        string res;
        for (int i = 0; i < numRows;++i) {
            for (int j = 0; j < col; ++j) {
                if (Matrix[i][j]) {
                    res += Matrix[i][j];
                }                               
            }
        }     
        res += '\0';
        return res;
    }
};
*/

/*按行排序
思路：通过从左向右迭代字符串，我们可以轻松地确定字符位于 Z 字形图案中的哪一行。

算法：
我们可以使用min(numRows,len(s)) 个列表来表示 Z 字形图案中的非空行。
从左到右迭代 s，将每个字符添加到合适的行。可以使用当前行和当前方向这两个变量对合适的行进行跟踪。
只有当我们向上移动到最上面的行或向下移动到最下面的行时，当前方向才会发生改变。

*/
/*
class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string res;
        for (string row : rows) res += row;
        return res;
    }
};
*/

/*
按行访问
思路
按照与逐行读取 Z 字形图案相同的顺序访问字符串。

算法
首先访问 行 0 中的所有字符，接着访问 行 1，然后 行 2，依此类推...
对于所有整数 k，行 0 中的字符位于索引 k(2⋅numRows−2) 处;
行numRows−1 中的字符位于索引 k(2⋅numRows−2)+numRows−1 处;
内部的 行 i 中的字符位于索引 k(2⋅numRows−2)+i 以及 (k+1)(2⋅numRows−2)−i 处;
*/

class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        string res;
        int n = s.size();
        int cycleLen = 2 * numRows - 2;     //一组z循环包含的字符数

        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j + i < n; j += cycleLen) {//j为字符的下标,i为其行号
                res += s[j + i];        //存储满列字符
                //cout << s[j + i] << " ";
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n) {
                    //若不进行j + cycleLen - i < n判断，在某些情况下会造成数组越界
                    //cout << " =" << s[j + cycleLen - i] << " ";
                    res += s[j + cycleLen - i];     //存储非满列字符                    
                }                    
            }
            //cout << endl;
        }
        return res;
    }
};

int main() {
    string s = "LEETCODEISHIRING";
    Solution sol;
    cout << sol.convert(s,4);
    return 0;
}

/*
难度：中等
2020.03.19~03.20
暴力破解法（找规律）：复杂度（n的平方）
执行用时 :
88 ms, 在所有 C++ 提交中击败了7.64%的用户
内存消耗 :
10.4 MB, 在所有 C++ 提交中击败了67.65%的用户

按行排序
执行用时 :
16 ms, 在所有 C++ 提交中击败了65.58%的用户
内存消耗 :
12.1 MB, 在所有 C++ 提交中击败了62.48%的用户

03.21
按行访问
执行用时 :
16 ms, 在所有 C++ 提交中击败了65.58%的用户
内存消耗 :
9.4 MB, 在所有 C++ 提交中击败了100.00%的用户
*/