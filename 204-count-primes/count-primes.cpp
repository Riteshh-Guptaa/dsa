class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        vector<char> isPrime(n, 1);
        isPrime[0] = isPrime[1] = 0;

        for (int i = 2; (long long)i * i < n; i++) {
            if (isPrime[i]) {
                for (long long j = (long long)i * i; j < n; j += i) {
                    isPrime[j] = 0;
                }
            }
        }

        int ans = 0;
        for (int i = 2; i < n; i++) {
            ans += isPrime[i];
        }
        return ans;
    }
};