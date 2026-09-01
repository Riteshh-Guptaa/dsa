class Solution {
public:
    int beautySum(string s) {
        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
            vector<int> v(26, 0);
            for(int j = i; j < s.size(); j++){
                v[s[j] - 'a']++;
                int mini = INT_MAX;
                int maxi = INT_MIN;
                int beauty = 0;
                for(int k = 0; k < 26; k++){
                    if(v[k] > 0){
                        mini = min(v[k], mini);
                    }
                    maxi = max(maxi, v[k]);
                }
                beauty = maxi - mini;
                cnt += beauty;
                
            }
        }
        return cnt;
    }
};