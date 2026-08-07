class Solution {
public:
    double reversal(double x, long int n){
        if(n == 0){
            return 1.0;
        }

        double half = reversal(x, n/2);
        if(n % 2 == 0){
            return half * half;
        }else{
            return x * half * half;
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