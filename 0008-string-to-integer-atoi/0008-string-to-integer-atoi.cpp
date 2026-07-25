class Solution {
public:
    int recursion(int i, int sign, string s, long long num){
        if(i == s.size() || !isdigit(s[i])){
            return (int)(sign * num);
        }
        int digit = s[i] - '0';
        if(num > INT_MAX/10 || num == INT_MAX/10 && digit > 7){
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        num = num * 10 + digit;
        return recursion(i + 1, sign, s, num);

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
        long long num = 0;
        return recursion(i, sign, s, num);
    }


};