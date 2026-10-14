class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
        [] (vector<int> &a, vector<int> &b) {
           return a[1] < b[1];
        });
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            if(ans.back()[1] <= intervals[i][0]){
                ans.push_back(intervals[i]);
            }
        }
        return intervals.size() - ans.size();
    }
};