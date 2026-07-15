class Solution {
public:
    long long finder(int mid, vector<int> &piles){
        long long cnt = 0;
        for(int num : piles){
            cnt += ceil(double(num)/mid);

        }
        return cnt;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        if(h < piles.size()) return -1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(finder(mid, piles) > h){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return low;
    }
};