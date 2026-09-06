class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0; 
        int r = 0;
        int maxFreq = 0;
        vector<int> v(26, 0);
        int ans = 0;
        while(r < s.size()){
            v[s[r] - 'A']++;
            maxFreq = max(maxFreq, v[s[r] - 'A']);
            if((r - l + 1) - maxFreq > k){
                v[s[l] - 'A']--;
                l++;
            }
         
            r++; 
        }
        return r - l;
    }
};