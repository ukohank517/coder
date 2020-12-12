struct PrimeNumbers {
    vector<bool> sieve;
    vector<long long> prime;

    PrimeNumbers (int n) : sieve(n+1,true) {
        sieve[0] = sieve[1] = false;
        for (long long i = 2; i < sieve.size(); i++) {
            if (sieve[i]) {
                prime.push_back(i);
                for (long long j = i * i; j < sieve.size(); j += i) {
                    sieve[j] = false;
                }
            }
        }
    }

    bool isPrime(long long n) {
        return sieve[n];
    }

    int size(void) {
        return (int) prime.size();
    }

    long long  operator [] (int n) {
        return  prime[n];
    }

};
/*
 O(N loglogN) ←早い!
 usage:
 PrimeNumbers prime(N); // Nまでの素数を列挙
 prime.size();  //素数の数
 prime[i]; //i番目の素数
 prime.isPrime(A); // bool, Aの素数判別
 */
