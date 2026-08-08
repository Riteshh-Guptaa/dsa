class Solution {
public:
    void reversal(vector<string> &ans, string curr, vector<string> &map, string digits, int idx){
        if(idx == digits.size()){
            ans.push_back(curr);
            return;
        }

        string letters = map[digits[idx] - '0'];

        for(char letter : letters){
            curr.push_back(letter);
            reversal(ans, curr, map, digits, idx + 1);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
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
        string curr = "";
        reversal(ans, curr, map, digits, 0);
        return ans;
    }


};