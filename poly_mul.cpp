ll mod = 998244353;
int G = 3;

ll power(ll x, ll n , ll mod)  
{
    if(n==0) return 1;
    if(x%mod==0) return 0;   
    n = n%(mod-1);
    ll pow = 1;
    while (n)
    {
        if (n & 1)
            pow = (pow*x)%mod;
        n = n >> 1;
        x = (x*x)%mod;
    }
    return pow;
}

ll imod(ll n , ll mod)
{
    if(n == 1) return 1;
    return (mod - (ll)(mod/n) * imod(mod%n , mod) % mod) % mod;
}


void NTT(vector < ll > & a, ll len, ll opt, vector < ll > & rev) {
  for (ll i = 0; i < len; i++)
    if (i < rev[i])
      swap(a[i], a[rev[i]]);
  for (ll i = 1; i < len; i <<= 1) {
    ll wn = power(G, (opt * ((mod - 1) / (i << 1)) + mod - 1) % (mod - 1), mod);
    ll step = i << 1;
    for (ll j = 0; j < len; j += step) {
      ll w = 1;
      for (ll k = 0; k < i; k++, w = (1ll * w * wn) % mod) {
        ll x = a[j + k];
        ll y = 1ll * w * a[j + k + i] % mod;
        a[j + k] = (x + y) % mod;
        a[j + k + i] = (x - y + mod) % mod;
      }
    }
  }
  if (opt == -1) {
    ll r = imod(len, mod);
    for (ll i = 0; i < len; i++)
      a[i] = 1ll * a[i] * r % mod;
  }
}

vi multiply(vi  a, vi  b) {
  ll n = a.size() - 1, m = b.size() - 1;
  ll tot = m + n;
  ll l = 0, len = 1;
  while (len <= tot) {
    len <<= 1;
    l++;
  }
  a.resize(len), b.resize(len);
  vector < ll > rev(len, 0), res(len, 0);
  for (ll i = 0; i < len; i++)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (l - 1));
  NTT(a, len, 1, rev); NTT(b, len, 1, rev);
  for (ll i = 0; i < len; i++)
    res[i] = (ll)(a[i] * b[i]) % mod;
  NTT(res, len, -1, rev);
  res.resize(tot + 1);
  return res;
}

vi find(mati& poly,int i,int j){
    int mid = (i+j)/2;
    if(i == j){
        return poly[i];
    }

    return multiply(find(poly,i,mid),find(poly,mid+1,j));
}