class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, int> mp;

        for(int x : arr){
            pq.push(x);
        }

        int r = 1;
        while(!pq.empty()){
            int x = pq.top();
            pq.pop();
            if(mp.find(x) == mp.end()){
                mp[x] = r++;
            }
        }

        for(int i = 0; i < arr.size(); i++){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};