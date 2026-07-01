class Solution {
public:
    double multiply(double x, long long n){
      if(n == 0){
        return 1;
      }

      double half = multiply(x, n/2);
      if(n % 2 == 0){
        return half * half;
      }

      return x * half * half;
    }
    double myPow(double x, long long n) {
        long long N = n;
        if(N < 0){
            return 1.0/multiply(x, -N);
        }
        return multiply(x, N);
    }
};