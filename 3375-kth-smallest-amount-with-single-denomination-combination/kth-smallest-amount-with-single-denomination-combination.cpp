class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
    long long lcm( long long a, long long b){
        return a / gcd(a, b) * b;
    }
    long long countNumbers(vector<int>& coins, long long x){
        int n = coins.size();
        long long count = 0;
        for (int mask = 1; mask < (1 << n); mask++){
            long long L = 1;
            int bits = 0;
            bool valid = true;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)){
                    bits++;
                    L = lcm(L, coins[i]);
                    if (L > x) {
                        valid = false;
                        break;
                    }
                }
            }
            if (!valid)
            continue;
            long long multiples = x / L;
            if (bits % 2 == 1)
            count += multiples;
            else
            count -= multiples;
        }
        return count;
    }
    long long findKthSmallest(vector<int>& coins, int K){
        long long low = 1;
        long long high = 1LL * (*min_element(coins.begin(),coins.end())) * K;
        while (low < high) {
            long long mid = low + (high - low) / 2;
            if (countNumbers(coins, mid) >= K)
            high = mid;
            else 
            low = mid + 1;
        }
        return low;
    }
};