class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for(char task : tasks){
            freq[task - 'A']++;
        }
        priority_queue<int> pq;

        for(int f : freq){
            if(f > 0){
                pq.push(f);
            }
        }

        int time = 0;

        while(!pq.empty()){
            vector<int> temp;
            int cycle = n + 1;

            while(cycle > 0 && !pq.empty()){
                int cnt = pq.top();
                pq.pop();

                cnt--;

                if(cnt > 0){
                    temp.push_back(cnt);
                }

                time++;
                cycle--;
            }

            for(int cnt : temp){
                pq.push(cnt);
            }

            if(!pq.empty()){
                time += cycle;
            }
        }
        return time;
    }
};