class Solution {
public:
    void reversal(vector<string> &ans, string num, int target, string move, long long curr, long long prev, int idx){
        if(idx == num.size()){
            if(curr == target){
                ans.push_back(move);
            }
            return;
        }

        for(int i = idx; i < num.size(); i++){
            if(i > idx && num[idx] == '0'){
                break;
            }

            string s = num.substr(idx, i - idx + 1);
            long long val = stoll(s);

            if(idx == 0){
                reversal(ans, num, target, s, val, val, i + 1);
            }else{
                reversal(ans, num, target, move + "+" + s, curr + val, val, i + 1);

                reversal(ans, num, target, move + "-" + s, curr - val, -val, i + 1);

                reversal(ans, num, target, move + "*" + s, curr - prev + prev * val, prev * val, i + 1);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        reversal(ans, num, target, "", 0, 0, 0);
        return ans;
    }
};