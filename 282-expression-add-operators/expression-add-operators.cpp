class Solution {
public:
    void reversal(vector<string> &ans, string num, string move, int target, long long curr, long long prev, int idx){
        if(idx == num.size()){
            if(curr == target){
                ans.push_back(move);
            }
            return;
        }

        for(int i = idx; i < num.size(); i++){
            if(i > idx && num[idx] == '0') break;
            string word = num.substr(idx, i - idx + 1);
            long long val = stoll(word);

            if(idx == 0){
                reversal(ans, num, word, target, val, val, i + 1);
            }else{
                reversal(ans, num, move + '+' + word, target, curr + val, val, i + 1);
                reversal(ans, num, move + '-' + word, target, curr - val, -val, i + 1);
                reversal(ans, num, move + '*' + word, target, curr - prev + (prev * val), prev * val, i+1);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string move = "";
        reversal(ans, num, move, target, 0, 0, 0);
        return ans;
    }
};