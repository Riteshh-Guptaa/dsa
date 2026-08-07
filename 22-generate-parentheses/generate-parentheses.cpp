class Solution {
public:
    void reversal(vector<string> &ans, string curr, int n, int open, int close){
        if(curr.size() == 2 * n){
            ans.push_back(curr);
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
        string curr;
        reversal(ans, curr, n, 0, 0);
        return ans;
    }
};