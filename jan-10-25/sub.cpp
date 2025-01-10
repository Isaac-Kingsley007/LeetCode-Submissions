#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int mp[26] = {};
        int w2[26] = {};

        for(const string& word :words2){
            for(char i: word) mp[i - 'a']++;

            for(int i = 0; i<26; i++){
                w2[i] = max(w2[i], mp[i]);
                mp[i] = 0;
            }
        }

        vector<string> ans;
        bool isValid;

        for(const string& word: words1){
            isValid = true;
            for(char i: word) mp[i - 'a']++;

            for(int i = 0; i<26; i++){
                if(mp[i] < w2[i]) isValid = false;
                mp[i] = 0;
            }

            if(isValid) ans.push_back(word);
        }

        return ans;
    }
};