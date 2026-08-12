class Solution {
public:
    void reversal(vector<string> &ans, string move, string num, int target, int idx, long long curr, long long prev){
        if(idx == num.size()){
            if(curr == target){
                ans.push_back(move);
            }
            return;
        }
        for(int i = idx; i < num.size(); i++){
            if(i > idx && num[idx] == '0') break;
            string newWord = num.substr(idx, i - idx + 1);
            long long val = stoll(newWord);
            if(idx == 0){
                reversal(ans, newWord, num, target, i + 1, val, val);
            }else{
                reversal(ans, move + '+' + newWord, num, target, i + 1, val + curr, val);
                reversal(ans, move + '-' + newWord, num, target, i + 1, curr - val, -val);
                reversal(ans, move + '*' + newWord, num, target, i + 1, curr - prev + (prev * val), prev * val);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string move = "";
        reversal(ans, move, num, target, 0, 0, 0);
        return ans;
    }
};