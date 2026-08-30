class Solution {
public:
    int dayFinder(vector<int> &bloomDay, int k, int mid){
        int cnt = 0;
        int ans = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= mid){
                cnt++;
            }else{
                ans += cnt/k;
                cnt = 0;
            }
        }
        ans += cnt/k;
        return ans;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        if(bloomDay.size() < 1LL * m * k) return -1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(dayFinder(bloomDay, k, mid) >= m){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};