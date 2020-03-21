#include <iostream>
#include <string>
#include <cstring>
#include <unordered_map>

using namespace std;
//#define false

#ifdef True
//滑动窗口，两个指针 *first 和 *second维护一个窗口，在用一个指针cur 从 *first指向的元素开始，比较窗口中是否有值与 *second指向的值相同
//时间复杂度 O(n^2)
int lengthOfLongestSubstring(string s) {

    const char *first = s.c_str();  //将string 转换为char[]
    const char *second = first;
    int res = 0;
    while (*first != '\0' && *second != '\0') {
        int len = 1;
        const char *cur = first;
        while (cur != second) {
            if (*cur == *second) {
                first = cur+1;  //"dvdf"
                break;
            }
            len++;
            cur++;
        }
        second++;
        res = res>len?res:len;
    }
    return res;
}

#else
int lengthOfLongestSubstring(string s) {

    unordered_map<char, int> umap;
    int move = 0, jump = 0;
    int res = 0;
    int len = s.length();
    while(move < len) {
        char tmp = s[move];
        //umap[tmp]>=jump 是为了排除 类似 tmmzuxt 这种情况，当重复的元素出现在 jump 指针前，应该忽略
        if(umap.find(tmp)!=umap.end() && umap[tmp]>=jump) {
            jump =  umap[tmp] + 1;
        }
        res = max(res,(move-jump+1));
        umap[tmp] = move;
        move++;
    }
    return res;
}

#endif

int main() {
    string str1 = "pwwkew";
    string str2 = "tmmzuxt";
    string str3 = "abcabcbb";
    string str4 = "bbbbb";
    cout << "3= "<<lengthOfLongestSubstring(str1) <<endl;
    cout << "5= "<<lengthOfLongestSubstring(str2) <<endl;
    cout << "3= "<<lengthOfLongestSubstring(str3) <<endl;
    cout << "1= "<<lengthOfLongestSubstring(str4) <<endl;
    return 0;
}
