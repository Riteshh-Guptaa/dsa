class Solution {
public:
    string minWindow(string s, string t) {
        int hash[256] = {0};

        for(int i = 0; i < t.size(); i++){
            hash[t[i]]++;
        }

        int r = 0, l = 0, startIdx = 0, count = 0, minLen = INT_MAX;

        while(r < s.size()){
            if(hash[s[r]] > 0){
                count++;
            }

            hash[s[r]]--;

            while(count == t.size()){
                if(r - l + 1 < minLen){
                    minLen = r - l + 1;
                    startIdx = l;
                }

                hash[s[l]]++;
                if(hash[s[l]] > 0){
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