ll modInverse(ll A,int mod = mod)
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

long long binpow(long long a, long long b,int mod = mod) {
    a %= mod;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int add(int a,int b,int mod = mod){
	if(a < 0)
	   a += mod;
	if(b < 0)
	   b += mod;   
	a %= mod;
	b %= mod;
	return (a+b)%mod;
}

int sub(int a,int b,int mod = mod){
	if(a < 0)
	   a += mod;
	if(b < 0)
	   b += mod;   
	a %= mod;
	b %= mod;
	return (a - b + mod)%mod; 
}

int mul(int a,int b,int mod = mod){
	if(a < 0)
	   a += mod;
	if(b < 0)
	   b += mod;   
	a %= mod;
	b %= mod;
	return (a*b)%mod;
}

int muli(int a,int b,int mod = mod){
	if(a < 0)
	   a += mod;
	if(b < 0)
	   b += mod;   
	a %= mod;
	b %= mod;
	b = modInverse(b)%mod;
	return (a*b)%mod;
}

void add_self(int& a,int b,int mod = mod){
    a = add(a,b,mod);
}

void sub_self(int& a,int b,int mod = mod){
	a = sub(a,b,mod);
}

void mul_self(int& a,int b,int mod = mod){
	a = mul(a,b,mod);
}

void muli_self(int& a,int b,int mod = mod){
    a = muli(a,b,mod);
}