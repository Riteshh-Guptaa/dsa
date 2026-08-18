class Solution {
public:
    string removeOuterParentheses(string s) {
        int j = 0, depth = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                depth++;
                if(depth > 1){
                    s[j++] = s[i];
                }
            }else{
                depth--;
                if(depth > 0){
                    s[j++] = s[i];
                }
            }
        }
        s.resize(j);
        return s;
    }
};