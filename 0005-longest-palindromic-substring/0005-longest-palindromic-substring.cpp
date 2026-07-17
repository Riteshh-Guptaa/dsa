class Solution {
public:
    string longestPalindrome(string s) {
       
        int maxi = 0;
        int idx = -1;
        for(int i = 0; i < s.size(); i++){
            int l = i;
            int r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                if(r - l + 1 > maxi){
                    maxi = r - l + 1;
                    idx = l;
                }
                l--;
                r++;
            }

            l = i;
            r = i + 1;

            while(l >= 0 && r < s.size() && s[l] == s[r]){
                if(r - l + 1 > maxi){
                    maxi = r - l + 1;
                    idx = l;
                }
                l--;
                r++;
            }

        }
        return s.substr(idx, maxi);
    }
};