class Solution {
public:
    int capacity(vector<int> &weights, int mid){
        int key = weights[0];
        int cnt = 0;
        for(int i = 1; i < weights.size(); i++){
            if(mid >= key + weights[i]){
                key += weights[i];
            }else{
                cnt++;
                key = weights[i];
            }
        }
        if(mid >= key) cnt++;
        return cnt;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 1);

        while(low <= high){
            int mid = low + (high - low)/2;

            if(capacity(weights, mid) > days){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return low;
    }
};