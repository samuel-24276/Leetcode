#include<iostream>
#include<string>
#include<vector>

using namespace std;

/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"
*/

/*暴力破解法，复杂度（n的3次幂），时间超限03.18~03.19*/
/*
class Solution {
public:
    bool isPalindrome(string s) {
        int size = s.size();
        for (int i = 0;i < size/2;++i) {
            if (s[i] != s[size - i - 1])
                return false;            
        }
        return true;
    }
    string longestPalindrome(string s) {
        int size = s.size();
        int max=0;         
        string ans;        
        for (int i = 0; i < size; ++i) {
            string str = s.substr(i);
            //>=的等号在这里是为了两个及以上不同字符的情况,若去掉=则需要下面被注释的判空语句
            for (int j = size-1;j >= i;--j) {   
                if (!isPalindrome(str)) {
                    str = s.substr(i, j-i);
                }
                else {
                    if (str.size() > max) {
                        max = str.size();
                        ans = str;
                    }                    
                }
            }            
        }
        
        //if (ans.empty())
        //    ans = s[0];
        return ans;
    }
};
*/

//最长公共子序列LCS方法行不通，若字符串中存在子串和它的倒序，答案会出错
/*动态规划
令dp[i][j]表示s[i]至s[j]所表示的子串是否回文，若回文，则为1，否则为0.
情况一：若s[i]==s[j]，那么只要s[i+1]至s[j-1]是回文，则dp[i][j]=1，否则=0
情况二：若s[i]!=s[j]，那么dp[i][j]=0

边界：dp[i][i]=1,dp[i][i+1] = (s[i]==s[i+1])?1:0

根据边界初始化时，dp[i][i]和dp[i][i+1]的值容易得出，若按照i和j从小到大的顺序枚举子串两个端点，
然后更新dp[i][j]，会无法保证dp[i+1][j-1]已经被计算过，无法得到正确的dp[i][j]，
如dp[0][4]递推dp[1][3]时，所以需要新的枚举方式
根据递推写法从边界开始的原理，注意到边界表示的是长度为1和2的子串，且每次转移时对子串长度减1，
因此不妨考虑按子串长度和子串的初始位置进行枚举，即第一遍将长度为3的子串的dp值全部求出，
第二遍再求长度为4的子串的dp值...
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if (len == 0 || len == 1)
            return s;
        int start = 0;//回文串起始位置
        int max = 1;//回文串最大长度
        vector<vector<int>>  dp(len, vector<int>(len));//定义二维动态数组
        for (int i = 0;i < len;++i)//初始化状态
        {
            dp[i][i] = 1;   //单个字符是回文字符串
            if (i < len - 1 && s[i] == s[i + 1])
            {
                dp[i][i + 1] = 1;   //连续两个字符相同是回文字符串
                max = 2;
                start = i;
            }
        }
        for (int l = 3;l <= len;++l)//l表示检索的子串长度，等于3表示先检索长度为3的子串
        {
            for (int i = 0;i + l - 1 < len;++i)
            {
                int j = l + i - 1;//终止字符位置
                if (s[i] == s[j] && dp[i + 1][j - 1] == 1)//状态转移
                {
                    dp[i][j] = 1;
                    start = i;
                    max = l;
                }
            }
        }
        return s.substr(start, max);//获取最长回文子串
    }
};

int main() {
    string s = "kyyrjtdplseovzwjkykrjwhxquwxsfsorjiumvxjhjmgeueafubtonhlerrgsgohfosqssmizcuqryqomsipovhhodpfyudtusjhonlqabhxfahfcjqxyckycstcqwxvicwkjeuboerkmjshfgiglceycmycadpnvoeaurqatesivajoqdilynbcihnidbizwkuaoegmytopzdmvvoewvhebqzskseeubnretjgnmyjwwgcooytfojeuzcuyhsznbcaiqpwcyusyyywqmmvqzvvceylnuwcbxybhqpvjumzomnabrjgcfaabqmiotlfojnyuolostmtacbwmwlqdfkbfikusuqtupdwdrjwqmuudbcvtpieiwteqbeyfyqejglmxofdjksqmzeugwvuniaxdrunyunnqpbnfbgqemvamaxuhjbyzqmhalrprhnindrkbopwbwsjeqrmyqipnqvjqzpjalqyfvaavyhytetllzupxjwozdfpmjhjlrnitnjgapzrakcqahaqetwllaaiadalmxgvpawqpgecojxfvcgxsbrldktufdrogkogbltcezflyctklpqrjymqzyzmtlssnavzcquytcskcnjzzrytsvawkavzboncxlhqfiofuohehaygxidxsofhmhzygklliovnwqbwwiiyarxtoihvjkdrzqsnmhdtdlpckuayhtfyirnhkrhbrwkdymjrjklonyggqnxhfvtkqxoicakzsxmgczpwhpkzcntkcwhkdkxvfnjbvjjoumczjyvdgkfukfuldolqnauvoyhoheoqvpwoisniv";
    Solution sol;
    cout << sol.longestPalindrome(s) << endl;
	return 0;
}

/*
最长回文字符串 难度：中等
动态规划法：2020.03.20
执行用时 :
208 ms, 在所有 C++ 提交中击败了36.37%的用户
内存消耗 :
185.7 MB， 在所有 C++ 提交中击败了18.22%的用户
*/