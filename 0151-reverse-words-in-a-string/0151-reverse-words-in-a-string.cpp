class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        string ans = "";
        while(i < s.size()){
            while(i < s.size() && s[i] == ' ') i++;
            if(i >= s.size()) break;
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