#include<string>
using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        
        if(s.size() < k) return false;
        if(s.size() == k) return true;

        int mp[26] = {};

        for(char i: s){
            mp[i - 'a'] ^= 1;
        }

        for(int i: mp) k -= i;

        return k > -1;
    }
};