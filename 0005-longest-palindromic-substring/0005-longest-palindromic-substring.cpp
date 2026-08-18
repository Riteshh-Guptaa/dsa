class Solution {
public:
    string longestPalindrome(string s) {
        int idx = -1, len = 0;
        for(int i = 0; i < s.size(); i++){
            int l = i;
            int r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                if(len < r - l + 1){
                    len = r - l + 1;
                    idx = l;
                }
                l--;
                r++;
            }

            l = i;
            r = i + 1;
            while(l >= 0 && r < s.size() && s[r] == s[l]){
                if(len < r - l + 1){
                    len = r - l + 1;
                    idx = l;
                }
                l--;
                r++;
            }
        }
        return s.substr(idx, len);

    }
};