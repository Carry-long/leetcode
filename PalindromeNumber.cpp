#include <iostream>
#include <string>
using namespace std;

bool isPalindrome1(int x) {

    string str = to_string(x);
    int len = str.length();
    const char *begin = str.c_str();
    const char *end = begin + len-1;
    while(begin < end) {
        if(*begin != *end){
            return false;
        }
        begin++;
        end--;
    }
    return true;
}

bool isPalindrome(int x) {

    if(x<0 || (x%10 ==0 && x!=0)) {  //x%10 ==0 && x!=0  如果像10这种会误判
        return false;
    }
    int tmp = 0;
    for(;tmp<x/10;x=x/10 ) {
        tmp = tmp*10 + x%10;
    }
    if(tmp ==x || tmp == x/10){  //tmp ==x 表示x有奇数位    tmp == x/10 表示x有偶数位
        return true;
    }

    return false;
}

int main() {

    cout << isPalindrome(1) << endl;
    cout << isPalindrome(121) << endl;
    cout << isPalindrome(1221) << endl;
    cout << isPalindrome(-121) << endl;
    cout << isPalindrome(10) << endl;
    return 0;
}

