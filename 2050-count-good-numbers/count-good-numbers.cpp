class Solution {
public:
    long long reversal(int x, long long n){
        int mod = 1e9 + 7;
        if(n == 0){
            return 1;

        }
        long long half = reversal(x, n/2);
        if(n % 2 == 0){
            return (half * half) % mod;

        }else{
            return (((x * half) % mod) * half) % mod;
        }
    }
    int countGoodNumbers(long long n) {
        int mod = 1e9 + 7;
        return (reversal(5, n/2 + n % 2) * reversal(4, n/2)) % mod;
    }
};