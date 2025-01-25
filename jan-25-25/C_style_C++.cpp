#include <vector>
#include <stdlib.h>
using namespace std;

typedef struct pairEntry{
    int first, second;
} upair;

int pairSorter(const void* a, const void* b){
    return (((upair*)a) -> first) - (((upair*)b) -> first);
}

int comp(const void* a, const void* b){
    return *((int*)a) - *((int*)b);
}

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        upair pairs[n];

        for (int i = 0; i < n; i++) {
            pairs[i].first = nums[i];
            pairs[i].second = i;
        }

        qsort(pairs, n, sizeof(upair), pairSorter);

        int indices[n];
        indices[0] = pairs[0].second;
        int lastStoped = 0;

        for (int i = 1; i < n; i++) {

            if (pairs[i].first - pairs[i - 1].first > limit) {

                qsort(indices + lastStoped, i - lastStoped, sizeof(int), comp);

                for (int j = lastStoped; j < i; j++) {
                    nums[indices[j]] = pairs[j].first;
                }

                lastStoped = i;
            }

            indices[i] = pairs[i].second;
        }

        if (lastStoped < n) {
            qsort(indices + lastStoped, n - lastStoped, sizeof(int), comp);

            for (int j = lastStoped; j < n; j++) {
                nums[indices[j]] = pairs[j].first;
            }
        }

        return nums;
    }
};