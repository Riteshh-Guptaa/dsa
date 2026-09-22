class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(int asteroid : asteroids){
            bool alive = true;
            while(!ans.empty() && alive && ans.back() > 0 && asteroid < 0){
                if(-asteroid > ans.back()){
                    ans.pop_back();
                }else if(-asteroid == ans.back()){
                    alive = false;
                    ans.pop_back();
                }else{
                    alive = false;
                }
            }
            if(alive) ans.push_back(asteroid);
        }
        return ans;
    }
};