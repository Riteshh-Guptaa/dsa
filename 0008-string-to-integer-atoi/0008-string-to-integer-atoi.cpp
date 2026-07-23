class Solution {
public:
    int reversal(long long ans, int sign, int i, string s){
        if(i == s.size() || !isdigit(s[i])){
            return ans * sign;
        }

        ans = ans * 10 + (s[i] - '0');
        if(sign == 1 && ans > INT_MAX){
            return INT_MAX;
        }

        if(sign == -1 && -1 * ans < INT_MIN){
            return INT_MIN;
        }

        return reversal(ans, sign, i + 1, s);
        
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
        long long ans = 0;
        return reversal(ans, sign, i, s);
        
    }
};