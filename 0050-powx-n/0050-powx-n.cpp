class Solution {
public:
    double reversal(double x, long long N){
        if(N == 0){
            return 1.00;
        }

        double half = reversal(x, N/2);
        if(N % 2 == 1){
           return  x * half * half;
        }else{
            return half * half;
        }
    }
    double myPow(double x, int n) {
        long long N = n;
        if(N < 0){
            x = 1/x;
            N = -N;
        }
        return reversal(x, N);
    }
};