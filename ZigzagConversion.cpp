#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string convert(string s, int numRows) {

    int len = s.length();
    if(len<=1 || numRows==1){
        return s;
    }
    if(numRows>len){
        numRows = len;
    }
    int flag = 0;;
    int jump = (numRows-1)*2;
    char cs[len];
    int index = 0;
    for(int i=0; i<numRows; i++) {
        int tmp = flag;
        cs[index++] = s[flag];
        while (true) {
            if((jump - 2 * i)!=0 && (tmp + jump - 2 * i)<len) {
                cs[index++] = s[tmp + jump - 2 * i];
                tmp += jump - 2 * i;
            }
            if( ((jump - 2 * i) < 2 * i) && ((tmp + jump - 2 * i) >= len)) {
                break;
            }
            if(i==0 && ((tmp + jump - 2 * i) >= len)) {
                break;
            }

            if (i!=0 && (tmp + 2 * i) <len) {
                cs[index++] = s[tmp+2 * i];
                tmp += 2 * i;
            }
            if(((jump - 2 * i) > 2 * i) && ((tmp + 2 * i) >=len)) {
                break;
            }
        }
        flag++;
    }
    string ret;
    for (char row : cs) {
        ret += row;
    }
    return ret;
}

int main() {

    string str1 = "PAYPALISHIRING";
//    cout<< str1 <<endl;
//    cout << "ABCD" <<endl;
    cout << convert(str1,4) <<endl;
    string str2 = "ABCD";
    cout << convert(str2,4) <<endl;
//    string str3 = "LEETCODEISHIRING";
//    cout << convert(str1,3) <<endl;
//    cout << convert(str1,3) <<endl;
return 0;
}