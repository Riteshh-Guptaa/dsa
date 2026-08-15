class Solution {
public:
    long long bloomFinder(vector<int> &bloomDay, int k, int mid){
        long long cnt = 0;
        long long total = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= mid){
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
        int low = 0;
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        if(bloomDay.size() < (long long)m * k) return -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(bloomFinder(bloomDay, k, mid) >= m){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};