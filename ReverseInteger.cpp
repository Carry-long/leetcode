#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;

int reverse(int x) {

    if(x>INT_MAX || x<INT_MIN) {
        return 0;
    }
    bool flag = false;
    if(x<0) {
        flag = true;
        x = abs(x);
    }
    string str = to_string(x);
    int len = str.size();

    for(int i = 0,j=len-1;i<j;) {
        char tmp = str[i];
        str[i++] = str[j];
        str[j--] = tmp;
    }
    double res = 0;
    int index = 0;
    for(int i = len-1;i>=0;i--) {
        res += (double) (str[i]-'0')* pow(10,index++);
    }
    if(res >=INT_MAX) {
        return 0;
    }
    if(flag) {
        return (int) -1*res;
    }
    return (int)res;
}

//将reverse优化
int reverse2(int x) {

    int flag = 1;
    if(x<0) {
        flag = -1;
        x = abs(x);
    }
    string str = to_string(x);
    int len = str.size();

    double res = 0;
    int index = 0;
    for(int i = 0; i<len; i++) {
        res += (double) (str[i]-'0')* pow(10,index++);
    }
    if(res >=INT_MAX) {
        return 0;
    }
    return (int) (flag * res);
}

//题中限制环境只能存储得下 32 位的有符号整数
//所以不能用long或double
int reverse3(int x) {
    int res = 0;
    while(x) {
        if(res>INT_MAX/10 ||res<INT_MIN/10){ //if后面有 res*10，如果这里 res>INT_MAX/10 ||res<INT_MIN/10，则下一步一定会越界
            return 0;
        }
        res = 10*res + x%10;
        x /= 10;
    }
    return res;
}

int main() {
//    cout << INT_MIN<<endl;
//    cout << INT_MAX<<endl;
    cout << reverse3(1534236469) << endl;
    cout << reverse3(-123) << endl;
    cout << reverse3(-1230) << endl;
    cout << reverse3(1230) << endl;
    return 0;
}


//1. 将x左端的n位先移动到y的低n位中，x>>(32-n);
//2. 将x左移n位，其右面低位补0，x<<n;
//3. 进行按位或运算(x >> (32 - n) | (x << n));