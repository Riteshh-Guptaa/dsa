class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0;
        int r = 0;
        int maxi = 0;
        unordered_map<int, int> mp;
        while(r < fruits.size()){
            mp[fruits[r]]++;
            if(mp.size() <= 2){
                maxi = max(maxi, r - l + 1);
            }else{
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0) mp.erase(fruits[l]);
                l++;
            }
            r++;
        }
        return maxi;
    }
};