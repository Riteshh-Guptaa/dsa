class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth = 0;
        int j = 0;
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