#include <iostream>
#include <vector>
using namespace std;

double findKthElm(vector<int>& nums1,vector<int>& nums2,int k);

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    int len = nums1.size() + nums2.size();
    double res = 0;
    if(len/2 != 0){
        res = findKthElm(nums1, nums2, (len/2)+1);
    } else {
        res = findKthElm(nums1, nums2, len/2) + findKthElm(nums1, nums2, (len/2)+1);
        res = res/2;
    }
    return res;
}

double findKthElm(vector<int>& nums1,vector<int>& nums2,int k) {

    int len1 = nums1.size();
    int len2 = nums2.size();
    int left = max(0, k-len2);
    int right = min(k, len1);
    //二分
    while(left<right) {
        int mid = (left+right)/2;
        if(nums1[mid]>=nums2[k-mid]){
            right = mid;
        } else {
            left = mid+1;
        }
    }



}


