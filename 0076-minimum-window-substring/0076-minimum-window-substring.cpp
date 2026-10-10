class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        int l = 0, r = 0, startIdx = -1, count = 0, minLen = INT_MAX;
        for(int i = 0; i < t.size(); i++){
            mp[t[i]]++;
        }

        while(r < s.size()){
            if(mp[s[r]] > 0){
                count++;
            }
            mp[s[r]]--;

            while(count == t.size()){
                if(r - l + 1 < minLen){
                    minLen = r - l + 1;
                    startIdx = l;
                }

                mp[s[l]]++;
                if(mp[s[l]] > 0){
                    count--;
                }

                l++;
            }
            r++;
        }
        if(minLen == INT_MAX) return "";
        return s.substr(startIdx, minLen);
    }
};