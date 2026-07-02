class Solution {
public:
    string reverseWords(string s) {
        int i = 0; 
        string sub = "";
        while(i < s.size()){
            while(i < s.size() && s[i] == ' ') i++;
            if(i == s.size()) break;
            int j = i;
            while(j < s.size() && s[j] != ' ') j++;
            if(sub.empty()) sub = s.substr(i, j - i);
            else sub = s.substr(i, j - i) + ' ' + sub;
            i = j;
        }

        return sub;
        
    }
};