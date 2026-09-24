class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(int asteroid : asteroids){
            bool alive = true;
            while(!ans.empty() && ans.back() > 0 && asteroid < 0 && alive){
                if(ans.back() < -asteroid){
                    ans.pop_back();
                }else if(ans.back() == -asteroid){
                    ans.pop_back();
                    alive = false;
                }else{
                    alive = false;
                }
            }
            if(alive) ans.push_back(asteroid);
        }
        return ans;
    }
};