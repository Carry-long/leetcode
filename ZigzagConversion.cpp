#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string convert(string s, int numRows) {

    int len = s.length();
    if(len<=1 || len<=numRows || numRows==1) {
        return s;
    }

    string ret;
    for(int i=0; i<numRows; i++) {
        int tag = (numRows - 1)*2;
        int jump = tag - i*2;
        int tmp = i;
        ret += s[tmp];    //初始化每一行开头
        if(jump ==0 || (tag-jump)==0) {
            while (true) {
                int maxValue = max(jump,tag-jump);
                if((tmp + maxValue) <len) {
                    ret += s[tmp + maxValue];
                    tmp += maxValue;
                } else {
                    break;
                }
            }
        } else {
            while (true) {
                if ((tmp + jump) < len) {
                    ret += s[tmp + jump];
                }
                tmp += jump;
                if (tmp >= len) {
                    break;
                }
                if ((tmp + tag - jump) < len) {
                    ret += s[tmp + tag - jump];
                }
                tmp += tag - jump;
                if (tmp >= len) {
                    break;
                }
            }
        }
    }
    return ret;
}

int main() {

    string str1 = "PAYPALISHIRING";
    cout<<"PAHNAPLSIIGYIR = " << convert(str1,3) <<endl;
    cout<<"PINALSIGYAHRPI = " << convert(str1,4) <<endl;

    string str2 = "ABCDE";
    //cout <<"ABDC = "<< convert(str2,3) <<endl;
    cout <<"ABCED = "<< convert(str2,4) <<endl;

    string str3 = "LEETCODEISHIRING";
    cout <<"LCIRETOESIIGEDHN = "<< convert(str3,3) <<endl;
    cout << "LDREOEIIECIHNTSG = " << convert(str3,4) <<endl;
    return 0;
}