class Solution {
public:
    int finder(vector<int> &weights, int mid){
        int cnt = 1;
        int sum = weights[0];
        for(int i = 1; i < weights.size(); i++){
            if(sum + weights[i] <= mid){
                sum += weights[i];
            }else{
                cnt++;
                sum = weights[i];
            }
        }

        return cnt;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low <= high){
            int mid = low + (high - low)/2;
            if(finder(weights, mid) <= days){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
        
    }
};