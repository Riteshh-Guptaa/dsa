class Solution {
public:
    void reversal(vector<string> &ans, string& digits, string curr, int idx, vector<string>& map){
        if(idx == digits.size()){
            ans.push_back(curr);
            return;
        }

        string digit = map[digits[idx] - '0'];

        for(char ch : digit){
            curr.push_back(ch);
            reversal(ans, digits, curr, idx + 1, map);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        vector<string> map = {
            "",
            ",",
            "abc",
            "def",
            "ghi",
            "jkl", 
            "mno",
            "pqrs", 
            "tuv",
            "wxyz"
        };

        vector<string> ans;
        string curr;

        reversal(ans, digits, curr, 0, map);
        return ans;
    }
};