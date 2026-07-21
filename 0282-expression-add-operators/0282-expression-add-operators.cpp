class Solution {
public:
    void reversal(string num, int target, int pos,
                  string path, vector<string> &ans,
                  long long curr, long long prev) {

        if (pos == num.size()) {
            if (curr == target)
                ans.push_back(path);
            return;
        }

        for (int i = pos; i < num.size(); i++) {

            if (i > pos && num[pos] == '0')
                break;

            string s = num.substr(pos, i - pos + 1);
            long long val = stoll(s);

            if (pos == 0) {
                reversal(num, target, i + 1, s, ans, val, val);
            } else {

                reversal(num, target, i + 1,
                         path + "+" + s,
                         ans,
                         curr + val,
                         val);

                reversal(num, target, i + 1,
                         path + "-" + s,
                         ans,
                         curr - val,
                         -val);

                reversal(num, target, i + 1,
                         path + "*" + s,
                         ans,
                         curr - prev + prev * val,
                         prev * val);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        reversal(num, target, 0, "", ans, 0, 0);
        return ans;
    }
};