#define N 200000
ll fact[1 + N];

void fill_fact() {
    fact[0] = 1;
    for (int i = 1; i <= N; ++i) {
        fact[i] = (i * fact[i - 1]) % mod;
    }
}

ll modInverse(ll A)
{
    ll M = mod;
    ll m0 = M;
    ll y = 0, x = 1;

    if (M == 1)
        return 0;

    while (A > 1) {
        // q is quotient
        ll q = A / M;
        ll t = M;

        // m is remainder now, process same as
        // Euclid's algo
        M = A % M, A = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
        x += m0;

    return x;
}

ll ncr(int n, int r) {
    if (r > n) {
        return 0;
    }

    ll num = fact[n];
    ll denom = (fact[n - r] * fact[r]) % mod;
    return (num * modInverse(denom)) % mod;
}