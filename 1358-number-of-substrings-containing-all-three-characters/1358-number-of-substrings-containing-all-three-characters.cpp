class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> v = {-1, -1, -1};
        int ans = 0;

        for(int r = 0; r < s.size(); r++){
            v[s[r] - 'a'] = r;
            ans += min(v[0], min(v[1], v[2])) + 1;

        }
        return ans;
        
    }
};