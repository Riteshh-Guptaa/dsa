class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        if(k == cardPoints.size()) return accumulate(cardPoints.begin(), cardPoints.end(), 0);
        if(k > cardPoints.size()) return -1;
        int lsum = 0;
        for(int i = 0; i < k; i++){
            lsum += cardPoints[i];
        }

        int maxi = lsum;
        int rIdx = cardPoints.size() - 1;

        for(int i = k - 1; i >= 0; i--){
            lsum -= cardPoints[i];
            lsum += cardPoints[rIdx--];
            maxi = max(lsum, maxi);
        }
        return maxi;
    }
};