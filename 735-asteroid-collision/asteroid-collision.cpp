class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for(int asteroid : asteroids){
            bool alive = true;
            while(!st.empty() && alive && st.back() > 0 && asteroid < 0){
                if(-asteroid == st.back()){
                    alive = false;
                    st.pop_back();
                }else if(-asteroid > st.back()){
                    st.pop_back();
                }else{
                    alive = false;
                }
            }

            if(alive) st.push_back(asteroid);
        }
        return st;
    }
};