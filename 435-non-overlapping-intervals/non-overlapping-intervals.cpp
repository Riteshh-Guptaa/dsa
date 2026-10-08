class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });

        int cnt = 1;
        int lastEnd = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++){
            if(lastEnd <= intervals[i][0]){
                cnt++;
                lastEnd = intervals[i][1];
            }
        }
        return intervals.size() - cnt;

    }
};