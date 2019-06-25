vector<long long> PrimeFactorization(long long n) {
    vector<long long> res;
    long long t = n;
    for (long long i = 2; i * i <= t; ){
        if (n % i == 0) res.push_back(i), n /= i;
        else i++;
    }
    if(n != 1) res.push_back(n);
    return res;
}
/*
 O(?)  10^6ぐらいは平気
 usage:
 vector<ll> ans = PrimeFactorization(N);// Nの素因数が全てansに入る。
 // 例: 8なら ans = {2,2,2};
 */
