class Solution {
public:
    int recursion(string s, int i, int sign, int ans){
        if(i == s.size() || !isdigit(s[i])){
            return sign * ans;
        }

        int digit = s[i] - '0';
        if(ans > INT_MAX/10 || ans == INT_MAX/10 && digit > 7){
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        ans = ans * 10 + digit;
        return recursion(s, i + 1, sign, ans);
    }
    int myAtoi(string s) {
        int i = 0;
        while(i < s.size() && s[i] == ' ') i++;
        if(i >= s.size()) return 0;
        int sign = 1;
        if(s[i] == '+' || s[i] == '-'){
            if(s[i] == '-'){
                sign = -1;
            }
            i++;
        }
        int ans = 0;
        return recursion(s, i, sign, ans);
    }
};