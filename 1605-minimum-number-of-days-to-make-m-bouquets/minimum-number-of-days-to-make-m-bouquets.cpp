class Solution {
public:
    long long bouquets(vector<int>& bloomDay, int mid, int k){
        long long cnt = 0;
        long long total = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(mid >= bloomDay[i]){
                cnt++;
            }else{
                total += cnt/k;
                cnt = 0;
            }
            
        }
        total += cnt/k;

      
        return total;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        if((long long)m * k > bloomDay.size()) return -1;
        while(low <= high){
            int mid = low + (high - low)/2;

            if(bouquets(bloomDay, mid, k) >= m){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};