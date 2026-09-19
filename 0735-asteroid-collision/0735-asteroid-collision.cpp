class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for(int a : asteroids){
            bool alive = true;
            while(!st.empty() && a < 0 && st.back() > 0 && alive){
                if(st.back() > -a){
                    alive = false;
                }else if(st.back() < -a){
                    st.pop_back();
                }else{
                    st.pop_back();
                    alive = false;
                }
            }
            if(alive) st.push_back(a);
        }
        return st;
    }
};