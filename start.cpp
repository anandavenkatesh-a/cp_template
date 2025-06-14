/*
    In the name of GOD
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #include <dbg.h>
using namespace std;
using namespace __gnu_pbds;
 
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define int             long long
#define inf LLONG_MAX
#define ninf LLONG_MIN
#define mod(a,b) (((a%b) + b)%b)
#define pi 3.1415926536
#define pb              push_back
#define ff              first
#define ss              second
#define mp(x,y)         make_pair(x,y)
#define all(x)          (x).begin(), (x).end()
#define precise(x,y)    fixed<<setprecision(y)<<x
#define NO                 {cout<<"NO"<<endl; return;}
#define YES             {cout<<"YES"<<endl; return;}
#define NEG1             {cout<<"-1"<<endl; return;}
#define setbits(x)      __builtin_popcountll(x)
typedef pair<int, int> pii;
#define pqb             priority_queue<int> // maxheap
#define pqs             priority_queue<int,vector<int>,greater<int>> // minheap
#define piipqs          priority_queue<pii,vector<pii>,greater<pii>> // minheap for pair<int,int>
#define piipqb          priority_queue<pii> // maxheap for pair<int,int>
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef bitset<32> b32;
typedef bitset<64> b64;
typedef vector<vector<int>> mati;
typedef vector<vector<ll>> matll;
typedef vector<bool> vb;
typedef queue<int> que;
typedef stack<int> stk;
typedef long double ld;
typedef vector<pii> vp;
 
int msb(int n){
    int k = __builtin_clzll(n);
    return 63 - k;  
}
 
ll mod = (1e9)+7;
 
void solve() {
   
}
 
signed main() {
 
#ifdef ONLINEJUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); //can need to change file . this one for taking input
    freopen("output.txt", "w", stdout); // this one for output
#endif
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
 
#ifdef ONLINEJUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC); // this line gives your code runtime
#endif
 
}
