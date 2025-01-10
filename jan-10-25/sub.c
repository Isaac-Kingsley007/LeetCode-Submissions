#include <stdlib.h>
#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** wordSubsets(char** words1, int words1Size, char** words2, int words2Size, int* returnSize) {
    int mp[26] = {};
    int w2[26] = {};

    for(int j = 0; j < words2Size; j++){
        for(int i = 0; words2[j][i]; i++) mp[words2[j][i] - 'a']++;

        for(int i = 0; i<26; i++){
            if(mp[i] > w2[i]) w2[i] = mp[i];
            mp[i] = 0;
        }
    }

    char** ans = malloc(sizeof(char *)*words1Size);
    int ptr = 0;
    bool isValid;

    for(int j = 0; j < words1Size; j++){
        isValid = true;
        for(int i = 0; words1[j][i]; i++) mp[words1[j][i] - 'a']++;

        for(int i = 0; i<26; i++){
            if(mp[i] < w2[i]) isValid = false;
            mp[i] = 0;
        }

        if(isValid) ans[ptr++] = words1[j];
    }

    *returnSize = ptr;
    return ans;

}