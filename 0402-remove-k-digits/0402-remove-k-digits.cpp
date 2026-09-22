class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        for(char ch : num){
            while(!ans.empty() && ans.back() > ch && k > 0){
                k--;
                ans.pop_back();
            }
            ans.push_back(ch);
        }
        while(k > 0){
            ans.pop_back();
            k--;
        }

        int i = 0;
        if(ans.empty()) return "0";
        while(ans[i] == '0') i++;
        if(i == ans.size()) return "0";
        string ans1 = ans.substr(i);
        return ans1;
    }
};