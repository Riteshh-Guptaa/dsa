class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        string ans = "";
        unordered_map<char, int> mpp;
        for(int i = 0; i < s.size(); i++){
            mpp[s[i]]++;
        }

        vector<vector<char>> v(n + 1);

        for(auto k : mpp){
            v[k.second].push_back(k.first);
        }

        for(int i = n; i >= 0; i--){
            for(char ch : v[i]){
                for(int j = 0; j < i; j++){
                    ans += ch;
                }
            }
        }
        return ans;
    }
};