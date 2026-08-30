class Solution {
public:
    long long bananaEaten(vector<int> &piles, int mid){
        long long cnt = 0;
        for(int i = 0; i < piles.size(); i++){
            cnt += ceil((double)piles[i]/mid);
        }
        return cnt;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        if(h < piles.size()) return -1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(bananaEaten(piles, mid) > h){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return low;
    }
};