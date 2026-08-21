class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int i = 0;
        while(i < s.size()){
            while(i < s.size() && s[i] == ' ') i++;
            if(i >= s.size()) return ans;
            int j = i;
            while(j < s.size() && s[j] != ' ') j++;
            string sub = s.substr(i, j - i);
            if(ans.empty()) ans = sub;
            else ans = sub + " " + ans;
            i = j;
        }
        return ans;

    }
};