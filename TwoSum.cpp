#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    int len = nums.size();
    cout << "twoSumlen = " << len <<endl;
    unordered_map<int, int> mmp;
    for(int i = 0; i<len; i++) {
        //pair<int ,int> myshopping (nums[i],i);
        mmp.insert(pair<int ,int>(nums[i],i));
    }
    for(int i = 0; i<len; i++) {
        int tmp = target - nums[i];
        unordered_map<int ,int>::const_iterator got = mmp.find(tmp);
        if(got != mmp.end() && got->second != i) {
            res.push_back(i);
            res.push_back(got->second);
            break;
        }
    }
    return res;
}

vector<int> twoSum2(vector<int>& nums, int target) {
    int len = nums.size();
    unordered_map<int, int> mmp;
    for(int i = 0; i<len; i++) {
        int tmp = target - nums[i];
        if(mmp.find(tmp) != mmp.end()) {
            return {mmp.find(tmp)->second,i};
        }
        mmp[nums[i]]=i;
    }
}

int main() {
    vector<int> val = {2,7,11,15};
    vector<int> res = twoSum2(val, 18);
    int len  = res.size();
    cout << "mainlen = " << len <<endl;
    for(int i = 0; i<len; i++) {
        cout << res[i] <<endl;
    }
}

