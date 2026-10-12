class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int r = 0, l = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(l < g.size() && r < s.size()){
            if(g[l] <= s[r]){
                l++;
                r++;
            }else{
                r++;
            }
        }
        return l;
        
    }
};