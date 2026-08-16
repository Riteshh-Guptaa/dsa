class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> v(26, 0);
        for(int i = 0; i < s.size(); i++){
            v[s[i] - 'a']++;
        }

        for(int j = 0; j < t.size(); j++){
            v[t[j] - 'a']--;
        }

        for(int k : v){
            if(k != 0){
                return false;
            }
        }
        return true;       
    }
};