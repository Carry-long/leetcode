#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

//超出时间限制
//将字符串A反转得到B，然后获取A的所有子串，在B中查询是否有相同子串，若有则判断子串是否是回文，是的话记录最长的回文。
string longestPalindrome(string s) {

    int len = s.length();
    if(len==1) {
        return s;
    }
    string rev = s;
    reverse(rev.begin(),rev.end());
    int res = 0;
    string str = "";
    for(int i=0;i<len;i++) {
        string tmp = "";
        for(int j =i;j<len;j++) {
            tmp += s[j];  //tmp 是 s 的子串，例如s= abcd，tmp就是a,ab,abc,abcd,b,bc...
            if(rev.find(tmp)!=-1) {
                string q=tmp;  //q用来验证temp是否是回文子串
                std::reverse(q.begin(),q.end());
                if(q==tmp) {
                    int a = tmp.length();
                    if(a > res) {
                        res =a ;
                        str = tmp;
                    }
                }
            }
        }
    }
    return str;
}

//动态规划
// 考虑  “ababa” 这个示例。如果我们已经知道 “bab” 是回文，那么很明显，“ababa” 一定是回文，因为它的左首字母和右尾字母是相同的。
// P(i,j) = P(i+1,j−1) and s[i] == s[j]

//s[i]==s[j] && dp[i+1][j-1]
//单一字母一定是回文，例如b，若b前后相同，如aba，也就当是 s[i]==s[j]，且 dp[i+1][j-1] = 1，一定是回文字符串
//i\j   a  b  a  b  a
//a     1     1     1
//b        1     1
//a           1
//b              1
//a                 1

//若s[i]==s[j]时，且i与j相邻，这时dp[i+1][j-1] 不再为1，所以满足s[i]==s[j] && j-i<2 即可
//s[i]==s[j] && (dp[i+1][j-1] || j-i<2)
//i\j  a  b  b  d
//a    1
//b       1  1
//b          1
//d             1

//综上，判断回文子串的条件为 if(s[i]==s[j] && (dp[i+1][j-1] || j-i<2)){}

string longestPalindrome2(string s) {
    int len = s.length();
    if(len<=1) {
        return s;
    }
//    使用变量来定义数组长度是，这个数组可以定义，却不能同时进行初始化赋值，需要在之后赋值。
//    int dp[len][len] = {0};  错误
    int dp[len][len];
    //std::fill函数的作用是：将一个区间的元素都赋予指定的值，即在[first, last)范围内填充指定值。
    //std::fill_n函数的作用是：在[fist, fist + count)范围内填充指定值
    fill_n(&dp[0][0],len*len,0);
    for(int i=0;i<len;i++) {
        dp[i][i] = 1;
    }

//    for(int i=0;i<len;i++) {
//        for(int j=0;j<len;j++){
//            dp[i][j] = 0;
//            if(i==j){
//                dp[i][j] = 1;
//            }
//        }
//    }
    int res = 1;
    int start = 0, end =0;
    for(int j=1; j<len; j++) {
        for(int i=0; i<j; i++) {
            if(s[i]==s[j] && (dp[i+1][j-1] || j-i<2)){
                dp[i][j] = 1;
                if((j-i+1)>res) {
                    res = j-i+1;
                    start = i;
                }
            }
        }
    }
    return s.substr(start,res);
}

int main() {
    string s1 = "bb";
    string s2 = "sknks";
    string s3 = "edfrgtyuiop";
    string s4 = "jglknendplocymmvwtoxvebkekzfdhykknufqdkntnqvgfbahsljkobhbxkvyictzkqjqydczuxjkgecdyhixdttxfqmgksrkyvopwprsgoszftuhawflzjyuyrujrxluhzjvbflxgcovilthvuihzttzithnsqbdxtafxrfrblulsakrahulwthhbjcslceewxfxtavljpimaqqlcbrdgtgjryjytgxljxtravwdlnrrauxplempnbfeusgtqzjtzshwieutxdytlrrqvyemlyzolhbkzhyfyttevqnfvmpqjngcnazmaagwihxrhmcibyfkccyrqwnzlzqeuenhwlzhbxqxerfifzncimwqsfatudjihtumrtjtggzleovihifxufvwqeimbxvzlxwcsknksogsbwwdlwulnetdysvsfkonggeedtshxqkgbhoscjgpiel";
    cout << longestPalindrome2(s1) <<endl;  //bb
    cout << longestPalindrome2(s2) <<endl;  //a
    cout << longestPalindrome2(s3) <<endl;  //e
    cout << longestPalindrome2(s4) <<endl;  //sknks
    cout << longestPalindrome(s4) <<endl;  //sknks
}