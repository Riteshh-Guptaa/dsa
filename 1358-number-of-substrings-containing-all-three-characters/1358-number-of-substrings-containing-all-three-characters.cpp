class Solution {
public:
    int numberOfSubstrings(string s) {
       int n = s.size();
       int last[3] = {-1, -1, -1};
       int ans = 0;

       for(int r = 0; r < n; r++){
        last[s[r] - 'a'] = r;
        ans += min({last[0], last[1], last[2]}) + 1;
       }
       return ans;
    }
};