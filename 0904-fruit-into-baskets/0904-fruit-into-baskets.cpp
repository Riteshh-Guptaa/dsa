class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0, r = 0, len = 0;
        unordered_map<int, int> mp;
        while(r < fruits.size()){
            mp[fruits[r]]++;
            if(mp.size() > 2){
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0) mp.erase(fruits[l]);
                l++;
            }

            if(mp.size() <= 2){
                len = max(r - l + 1, len);
            }
          
            r++;
        }
        return len;   
    }
};