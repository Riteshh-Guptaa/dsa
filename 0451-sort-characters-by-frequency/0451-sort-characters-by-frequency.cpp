class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
        }
        int n = s.size();
        string ans = "";
        vector<vector<char>> ch(n + 1);
        for(auto i : mp){
            ch[i.second].push_back(i.first);
        }

        for(int i = n; i >= 1; i--){
            for(char c : ch[i]){
                for(int j = 0; j < i; j++){
                    ans += c;
                }
            }
        }
        return ans;
    }
};