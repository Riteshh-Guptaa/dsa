class Solution {
public:
    long long eater(vector<int> &piles, int mid){
        long long cnt = 0;
        for(int i = 0; i < piles.size(); i++){
            cnt += ceil((double)piles[i]/mid);
        }
        return cnt;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = INT_MIN;
        for(int i = 0; i < piles.size(); i++){
            high = max(high, piles[i]);
        }
        if(h < piles.size()) return -1;
        while(low <= high){
            int mid = low + (high - low)/2;

            if(eater(piles, mid) > h){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return low;
    }
};