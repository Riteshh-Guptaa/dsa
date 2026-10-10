class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int maxFreq  = 0;
        int len = 0;
        unordered_map<char, int> mp;
        while(r < s.size()){
            mp[s[r]]++;
            maxFreq = max(maxFreq, mp[s[r]]);
            if((r - l + 1) - maxFreq > k){
                mp[s[l]]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }

            if((r - l + 1) - maxFreq <= k){
                len = max(len, r - l + 1);
            }
            r++;
        }
        return len;
    }
};