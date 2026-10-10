class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        unordered_map<char, int> mp;
        int len = 0;
        while(r < s.size()){
            if(mp.find(s[r]) != mp.end()){
                l = max(mp[s[r]] + 1, l);
            }
            len = max(len, r - l + 1);
            mp[s[r]] = r;
            r++;
        }
        return len;

    }
};