#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = pref.size(), wl, isans;
        int ans = 0;
        for (const string& word: words) {
            wl = word.size();
            if (wl >= n) {
                isans = 1;
                for (int j = 0; j < n; j++) {
                    if (word[j] != pref[j]) {
                        isans = 0;
                        break;
                    }
                }
                ans += isans;
            }
        }

        return ans;
    }
};

int main(){

}