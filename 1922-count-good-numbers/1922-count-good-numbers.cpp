class Solution {
public:
    const long long mod = 1e9 + 7;
    long long pow(int x, long long y){
        if(y == 0){
            return 1;

        }

        long long half = pow(x, y/2);

        if(y % 2 == 0){
            return (half * half) % mod;
        }

        return (((half * half) % mod) * x) % mod;
    }
    int countGoodNumbers(long long n) {
        int ans =(pow(5, (n/2 + n % 2)) * pow(4, n/2)) % mod;
        return ans;
    }
};