#include<iostream>
using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int bt = -1, dt = -1;
        int n = s.size();
        int dbit[n], bracket[n];

        for (int i = 0; i<n; i++) {
            if (locked[i] == '0')
                dbit[++dt] = i;

            else if (s[i] == '(')
                bracket[++bt] = i;

            else {
                if (bt >= 0)
                    bt--;
                else if (dt >= 0)
                    dt--;
                else
                    return false;
            }
        }

        while (bt >= 0 && dt >= 0 && bracket[bt] < dbit[dt])
            bt--, dt--;

        if (bt >= 0)
            return false;

        return (dt + 1) % 2 == 0;
    }
};