#include <stdbool.h>

bool canConstruct(char* s, int k) {
    int len = strlen(s);
    if(len < k) return false;
    if(len == k) return true;

    int mp[26] = {};

    for(int i = 0; i<len; i++){
        mp[s[i] - 'a'] ^= 1;
    }

    for(int i = 0; i<26; i++) k -= mp[i];

    return k > -1;
}