class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int maxi =0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                depth++;
            }else if(s[i] == ')'){
                maxi = max(depth, maxi);
                depth--;
            }
        }
        return maxi;
    }
};