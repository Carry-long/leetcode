#include <iostream>
#include <string>
using namespace std;

int myAtoi(string str) {
    int len = str.length();
    int start =0;
    for(;start<len;start++) {
        if(str[start]==' ') {
            continue;
        }
        if((str[start]<'0'|| str[start]>'9') && (str[start]!='-' && str[start]!='+')) {
            return 0;
        } else {
            break;
        }
    }

    int tag = 1;
    if(str[start]=='-') {
        tag = -1;
    }
    if((str[start]=='-' || str[start]=='+')) {
        start++;
    }

    int end = start;
    for(; end<len; end++) {
        if(str[end]>='0'&& str[end]<='9') {
            continue;
        } else {
            break;
        }
    }
    end--;
    if(end==start && (str[start]=='-' || str[start]=='+')){  //防止出现 "-"的情况
        return 0;
    }

    int res = 0;
    for(int i=start;i<=end;i++) {
        int tmp = str[i] - '0';
        if(tag>0 && (res> INT_MAX/10 ||(res== INT_MAX/10 && tmp >=7))) {
            return INT_MAX;
        }
        if(tag<0 && (res> INT_MAX/10 ||(res== INT_MAX/10 && tmp >=8))) {
            return INT_MIN;
        }
        res = res * 10 + tmp;
    }
    return tag * res;
}

//简化
int myAtoi2(string str) {
    int len = str.length();
    int start =0;
    for(;start<len;start++) {
        if(str[start]!=' ') {
            break;
        }
    }

    int tag = 1;
    if(str[start]=='-') {
        tag = -1;
    }
    if((str[start]=='-' || str[start]=='+')) {
        start++;
    }

    int res = 0;
    for(int i=start;i<len;i++) {
        if(str[i]<'0' || str[i]>'9') {
            break;
        }
        int tmp = str[i] - '0';
        //最大正数 2147483647
        if(tag>0 && (res> INT_MAX/10 || (res== INT_MAX/10 && tmp >=7))) {
            return INT_MAX;
        }
        //最小负数 -2147483648
        if(tag<0 && (res> INT_MAX/10 || (res== INT_MAX/10 && tmp >=8))) {
            return INT_MIN;
        }
        res = res * 10 + tmp;
    }
    return tag * res;
}

int main() {
    cout<< myAtoi2("      2") <<endl;
    cout<< myAtoi2("     - 2") <<endl;
    cout<< myAtoi2("      -ab") <<endl;
    cout<< myAtoi2("42") <<endl;
    cout<< myAtoi2("   -42") <<endl;
    cout<< myAtoi2("-4193 with words") <<endl;
    cout<< myAtoi2("words and 987") <<endl;
    cout<< myAtoi2("-91283472332") <<endl;
    cout<< myAtoi2("-2147483648") <<endl;
    cout<< myAtoi2("2147483648") <<endl;
    cout<< myAtoi2("2147483647") <<endl;
    return 0;
}