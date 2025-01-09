int prefixCount(char** words, int wordsSize, char* pref) {
    int n = strlen(pref), wl, isans;
    int ans = 0;
    for(int i = 0; i<wordsSize; i++){
        wl = strlen(words[i]);
        if(wl >= n){
            isans = 1;
            for(int j = 0; j<n; j++){
                if(words[i][j] != pref[j]){
                    isans = 0;
                    break;
                }
            }
            ans += isans;
        }
    }

    return ans;
}