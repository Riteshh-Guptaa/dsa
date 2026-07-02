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

                for(int i = 0; i < 26; i++){
                    if(v[i] >= 1){
                        mini = min(mini, v[i]);
                    }
                    maxi = max(maxi, v[i]);
                }

                int beauty = maxi - mini;
                cnt += beauty;
            }


        }
        return cnt;
        
    }
};