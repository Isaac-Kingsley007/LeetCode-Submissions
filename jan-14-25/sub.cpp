#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int mp[51] = {};

        int comm = 0;
        vector<int> ans(n);

        for(int i = 0; i<n; i++){
            mp[A[i]]++;
            if(mp[A[i]] == 2) comm++;
            mp[B[i]]++;
            if(mp[B[i]] == 2) comm++;

            ans[i] = comm;
        }

        return ans;
    }
};