class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int i = 1;
        int sum = 1;

        while(i < n){
            while(i < n && ratings[i] == ratings[i - 1]){
                i++;
                sum++;
            }

            int peak = 1;
            while(i < n && ratings[i] > ratings[i - 1]){
                peak++;
                i++;
                sum += peak;
            }

            int down = 1;

            while(i < n && ratings[i] < ratings[i - 1]){
             
                i++;
                sum += down;
                down++;
            }

            if(down > peak){
                sum += down - peak;
            }
        }
        return sum;

    }
};