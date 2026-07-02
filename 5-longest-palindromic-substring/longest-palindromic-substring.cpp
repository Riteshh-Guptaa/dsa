class Solution {
public:
    string longestPalindrome(string s) {
        int length = 0;
        int maxi = 0;
        int idx = 0;
        for(int i = 0; i < s.size(); i++){
            int left = i;
            int right = i;
            while(left >= 0 && right < s.size() && s[left] == s[right]){
                length = right - left + 1;
                left--;
                right++;
            }
            if(maxi < length){
                idx = left + 1;
                maxi = length;
            }

            left = i;
            right = i + 1;
            length = 0;

            while(left >= 0 && right < s.size() && s[left] == s[right]){
                length = right - left + 1;
                left--;
                right++;
            }

            if(maxi < length){
                idx = left + 1;
                maxi = length;
            }
            length = 0;

        }
        return s.substr(idx, maxi);
        
    }
};