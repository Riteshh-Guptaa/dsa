class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        for(char ch : num){
            while(!ans.empty() && ch < ans.back() && k > 0){
                ans.pop_back();
                k--;
            }
            ans.push_back(ch);
        }

        while(k > 0){
            ans.pop_back();
            k--;
        }

        int i = 0;
        while(ans[i] == '0') i++;
        if(ans.empty()) return "0";
        if(i == ans.size()) return "0";
        return ans.substr(i);
    }
};