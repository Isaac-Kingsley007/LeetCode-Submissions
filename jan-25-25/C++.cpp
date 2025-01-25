#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int,int>> pairs(n);

        for(int i = 0; i<n; i++){
            pairs[i] = {nums[i], i};
        }

        std::sort(pairs.begin(), pairs.end());

        int indices[n];
        indices[0] = pairs[0].second;
        int lastStoped = 0;

        for(int i = 1; i < n; i++){

            if(pairs[i].first - pairs[i-1].first > limit){

                std::sort(indices + lastStoped, indices + i);

                for(int j = lastStoped; j < i; j++){
                    nums[indices[j]] = pairs[j].first;
                }

                lastStoped = i;
            }

            indices[i] = pairs[i].second;

        }

        if(lastStoped < n){
            std::sort(indices + lastStoped, indices + n);

            for(int j = lastStoped; j < n; j++){
                nums[indices[j]] = pairs[j].first;
            }
        }

        return nums;
    }
};