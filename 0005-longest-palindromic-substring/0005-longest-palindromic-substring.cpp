class Solution {
public:
    string longestPalindrome(string s) {
        int l = 0;
        int r = 0;
        int maxi = 0;
        int idx = 0;
        int length = 0;
        for(int i = 0; i < s.size(); i++){
            l = i;
            r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                length = r - l +1;
                l--;
                r++;
                
            }
            if(maxi < length){
                idx = l + 1;
                maxi = length;
            }

            l = i;
            r = i + 1;
            while(l >= 0 && r < s.size() && s[r] == s[l]){
                
                length = r - l + 1;
                l--;
                r++;
                
            }
            if(maxi < length){
                    idx = l + 1;
                    maxi = length;
                }
        }
        return s.substr(idx, maxi);
    }
};