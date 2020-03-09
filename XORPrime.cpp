long long findSubsets(int num, vector<int> &setPrimes, int index, int mod) {
    long long result = 0ll;
    if(index == setPrimes.size()) {
        return (result + num) % mod;
    }
    result = (result + findSubsets(num ^ setPrimes[index], setPrimes, index + 1, mod)) % mod;
    result = (result + findSubsets(num, setPrimes, index + 1, mod)) % mod;
    return result % mod;
}
int Solution::solve(vector<int> &A) {
    int n = sqrt(pow(10, 9)) + 1, mod = pow(10, 9) + 7;
    vector<int> primes, sieve(n+1, 0);
    for(int i=2; i<=n; i++) {
        if(sieve[i] == 0) {
            primes.push_back(i);
            for(int j = i*i; j <= n ; j += i) {
                sieve[j] = 1;
            }
        }
    }
    long long result = 0ll;
    for(int i=0; i<A.size(); i++) {
        int ele = A[i];
        vector<int> setPrimes;
        for(int j = 0; j < primes.size(); j++) {
            if(ele % primes[j] == 0) {
                setPrimes.push_back(primes[j]);
                while(ele % primes[j] == 0) {
                    ele = ele / primes[j];
                }
            }
        }
        if(ele != 1) {  // if the number is a big prime number itself
            setPrimes.push_back(ele);
        }
        result = (result + findSubsets(0, setPrimes, 0, mod)) % mod;
    }
    while(result < 0) {
        result += mod;
    }
    return (int)(result % mod);
}
