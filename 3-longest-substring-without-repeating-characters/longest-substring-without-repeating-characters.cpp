class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l = 0;
        int r = 0;
        int maxi = 0;
        while(r < s.size()){
            if(mp.find(s[r]) != mp.end()){
                l = max(mp[s[r]] + 1, l);
            }
            maxi = max(r - l + 1, maxi);
            mp[s[r]] = r;
            r++;
            
        }
        return maxi;
    }
};