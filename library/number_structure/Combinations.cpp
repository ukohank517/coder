struct Combinations {
    
    long long mod;
    vector< long long > inv;
    vector< long long > fact;
    vector< long long > inv_fact;
    
    Combinations (int n, int m) : inv(n), fact(n), inv_fact(n), mod(m) {
        inv[1] = 1;
        for (long long i = 2; i < n; i++) {
            inv[i] = inv[mod%i] * (mod - mod / i) % mod;
        }
        fact[0] = inv_fact[0] = 1;
        for (long long i = 1; i < n; i++) {
            fact[i] = (fact[i-1] * i) % mod;
            inv_fact[i] = (inv_fact[i-1] * inv[i]) % mod;
        }
    }
    
    long long nPr(long long n, long long r) {
        if (n < r || r < 0) return 0;
        return fact[n] * inv_fact[n-r] % mod;
    }
    
    long long nCr(long long n, long long r) {
        if (n < r || r < 0) return 0;
        return nPr(n,r) * inv_fact[r] % mod;
    }
    
    long long nHr(long long n, long long r) {
        return nCr(n+r-1,r);
    }
    
};
/*
 usage:
 O(N);
 Combination C(N,inf);//Nまでの全てのcombination, %inf;
 C.nCr(a,b); // aCbの値
 C.nPr,  C.nHrなどもある
 */
