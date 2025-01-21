#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long p1 = 0, p2 = 0, curr = LLONG_MAX, ans = LLONG_MAX;

        for(int i: grid[0]) p1 += i;

        int n = grid[0].size();

        for(int i = 0; i<n; i++){
            p1 -= grid[0][i];
            curr = max(p1,p2);
            if(curr <= ans) ans = curr;
            else break;
            p2 += grid[1][i];
        }

        return ans;
    }
};