class Solution {
public:
    int myAtoi(string s) {
        int i = 0;

        while(i < s.size() && s[i] == ' '){
            i++;
        }
        if(i >= s.size()) return 0;
        int sign = 1;
        if(i < s.size() && (s[i] == '+' || s[i] == '-')){
            if(s[i] == '-'){
                sign = -1;
            }
            i++;
        }

        long long ans = 0;

        while(i < s.size() && isdigit(s[i])){
            ans = ans * 10 + (s[i] - '0');
            i++;
            if(sign * ans > INT_MAX){
                return INT_MAX;
            }
            if(sign * ans < INT_MIN) return INT_MIN;
        }
        return (int)sign * ans;
    }
};