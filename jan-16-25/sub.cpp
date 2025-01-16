#include<vector>
using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        if(nums1.size() & 1) for(int i: nums2) ans ^= i;
        if(nums2.size() & 1) for(int i: nums1) ans ^= i;
        return ans;
    }
};