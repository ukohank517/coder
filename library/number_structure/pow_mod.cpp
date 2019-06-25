long long pow_mod(long long n, long long k, long long mod) {
    long long ret = 1, a = n % mod;
    while (k > 0) {
        if (k & 1) ret = (ret * a) % mod;
        a = (a * a) % mod;
        k >>= 1;
    }
    return ret;
}
/*
 O(log K)
 usage:
 pow_mod(N,K,inf); // (N^K)%inf
 */
