class Solution {
public:
    void solve(int open, int close, vector<string> &ans, string curr, int n){
        if(curr.size() == 2 * n){
            ans.push_back(curr);
            return;
        }
        if(open < n){
            curr.push_back('(');
            solve(open + 1, close, ans, curr, n);
            curr.pop_back();
        }
        if(close < open){
            curr.push_back(')');
            solve(open, close + 1, ans, curr, n);
            curr.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr = "";
        int open = 0, close = 0;
        solve(0, 0, ans, curr, n);
        return ans;

    }
};