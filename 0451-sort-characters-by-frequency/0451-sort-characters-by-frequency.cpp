class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
        }

        vector<vector<char>> v(s.size() + 1);
        for(auto x : mp){
            v[x.second].push_back(x.first);
        }

        for(int i = s.size(); i >= 0; i--){
            for(char ch : v[i]){
                for(int j = 0; j < i; j++){
                    ans += ch;
                }
            }
        }
        return ans;
    }
};