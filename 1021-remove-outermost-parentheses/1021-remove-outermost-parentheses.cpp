class Solution {
public:
    string removeOuterParentheses(string s) {
        int j = 0;
        int depth = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                if(depth > 0){
                    s[j++] = s[i];
                }
                depth++;
            }
            else{
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