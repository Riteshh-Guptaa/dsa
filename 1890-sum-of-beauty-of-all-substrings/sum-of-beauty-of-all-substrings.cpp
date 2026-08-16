class Solution {
public:
    int beautySum(string s) {
        int cnt = 0;
        int beauty = 0;
        for(int i = 0; i < s.size(); i++){
            vector<int> v(26, 0);
            
            for(int j = i; j < s.size(); j++){
                int mini = INT_MAX;
            int maxi = INT_MIN;
                v[s[j] - 'a']++;
                for(int k = 0; k < 26; k++){
                    
                    if(v[k] >= 1){
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