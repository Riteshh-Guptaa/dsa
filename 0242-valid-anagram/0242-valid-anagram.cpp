class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> v(26, 0);
        for(int i = 0; i < s.size(); i++){
            v[s[i] - 'a']++;
        }
        for(int i = 0; i < t.size(); i++){
            v[t[i] - 'a']--;
        }

        for(int x : v){
            if(x != 0){
                return false;
            }
        }
        return true;
    }
};