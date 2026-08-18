class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
        }

        vector<vector<char>> v(s.size() + 1);

        for(auto i : mp){
            v[i.second].push_back(i.first);
        }

        string ans = "";

        for(int i = s.size(); i >= 1; i--){
            for(char ch : v[i]){
                for(int j = 0; j < i; j++){
                    ans += ch;
                }
            }
        }
        return ans;
    }
};