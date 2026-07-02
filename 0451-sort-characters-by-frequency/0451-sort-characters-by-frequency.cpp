class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        for(int i = 0; i < s.size(); i++){
            freq[s[i]]++;
        }

        int n = s.size();
        string ans = "";

        vector<vector<char>> v(s.size() + 1);
        for(auto &p : freq){
            v[p.second].push_back(p.first);
        }

        for(int f = n; f >= 1; f--){
            for(char c : v[f]){
                ans.append(f, c);
            }
        }
        return ans;
    }
};