class Solution {
public:
    int helper(string &s, long long ans, int sign, int i){
        if(i >= s.size() || !isdigit(s[i])){
            return sign * ans;
        }
        
        ans = ans * 10 + (s[i] - '0');
        if(sign == 1 && ans > INT_MAX){
            return INT_MAX;
        }

        if(sign == -1 && -1 * ans < INT_MIN) return INT_MIN;
        return helper(s, ans, sign, i + 1);
    }
    int myAtoi(string s) {
        int ans = 0;
        int sign = 1;
        int i = 0;
        while(i < s.size() && s[i] == ' ') i++;
        if(i >= s.size()) return 0;
        if(i < s.size() && (s[i] == '+' || s[i] == '-')){
            if(s[i] == '-'){
                sign = -1;
            }
            i++;
        }
        return helper(s, ans, sign, i);
    }
};