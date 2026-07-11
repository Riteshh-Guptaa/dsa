class Solution {
public:
    void reversal(vector<string>& ans, string& curr, int n, int open, int close){
        if(2 * n == curr.size()){
            ans.push_back(curr);
            return;
        }

        if(open < n){
            curr.push_back('(');
            reversal(ans, curr, n, open + 1, close);
            curr.pop_back();
        }

        if(close < open){
            curr.push_back(')');
            reversal(ans, curr, n, open, close + 1);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr = "";
        int open = 0, close = 0;
        reversal(ans, curr, n, open, close);
        return ans;
    }
};