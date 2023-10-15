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

long long binpow(long long a, long long b) {
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

int add(int a,int b){
	if(a < 0)
	   a += mod;
	if(b < 0)
	   b += mod;   
	a %= mod;
	b %= mod;
	return (a+b)%mod;
}

int sub(int a,int b){
	if(a < 0)
	   a += mod;
	if(b < 0)
	   b += mod;   
	a %= mod;
	b %= mod;
	return (a - b + mod)%mod; 
}

int mul(int a,int b){
	if(a < 0)
	   a += mod;
	if(b < 0)
	   b += mod;   
	a %= mod;
	b %= mod;
	return (a*b)%mod;
}

int muli(int a,int b){
	if(a < 0)
	   a += mod;
	if(b < 0)
	   b += mod;   
	a %= mod;
	b %= mod;
	b = modInverse(b)%mod;
	return (a*b)%mod;
}

void self_add(int& a,int b){
    a = add(a,b);
}

void self_sub(int& a,int b){
	a = sub(a,b);
}

void self_mul(int& a,int b){
	a = mul(a,b);
}

void self_muli(int& a,int b){
    a = muli(a,b);
}