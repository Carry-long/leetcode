#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    int a= 10;
    void *b = &a;

    printf("int a = %d\n",a);
    printf("void (int *)b =%d \n",*(int *)b);
    printf("void (double *)b =%d \n",*(float*)b);
    cout<< typeof(*(float*)b) << endl;

    return 0;
}