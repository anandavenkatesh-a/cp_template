#include<bits/stdc++.h>
using namespace std;

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

ll mod = (1e9) + 7;

//understand the question properly(what we need to find)
//workout sample inputs with hand
//think along with constarints
//is ok to brute force or simulate
//write generalized statements
//understand i/o properly
//dont debug the code too much rewrite
//there should some progess with every 5 mins
//properly write the math equations in paper
//if recursive appraoch is not working then try iterative approach
//use calculater not google search
//every problems may be different but not difficult
//thinking in reverse direction might work
//with binary search think in reverse direction
//either sorting or multiset and multimap when it comes sorting

int n, m;

void solve() {
    cin >> n >> m;
    vector<vector<pii>> alist(n);
    piipqs q;
    while (m--) {
        int a, b; cin >> a  >> b;
        --a;
        --b;
        int w; cin >> w;
        alist[a].push_back({w, b});
    }

    vi count(n, 0), min_path(n, INT_MAX), max_path(n, INT_MIN), dist(n, INT_MAX);
    count[0] = 1;
    dist[0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
        pii curr = q.top();
        q.pop();

        if (curr.ff > dist[curr.ss]) {
            continue;
        }

        for (pii x : alist[curr.ss]) {
            if (dist[x.ss] == (curr.ff + x.ff)) {
                count[x.ss] += count[curr.ss];
                min_path[x.ss] = min(min_path[x.ss], 1 + min_path[curr.ss]);
                max_path[x.ss] = max(max_path[x.ss], 1 + max_path[curr.ss]);
            }
            else if (dist[x.ss] > (curr.ff + x.ff)) {
                dist[x.ss] = curr.ff + x.ff;
                count[x.ss] = count[curr.ss];
                min_path[x.ss] = min(min_path[x.ss], 1 + min_path[curr.ss]);
                max_path[x.ss] = max(max_path[x.ss], 1 + max_path[curr.ss]);
            }
        }
    }

    cout << dist[n - 1] << " " << count[n - 1] << " " << min_path[n - 1] << " " << max_path[n - 1] << "\n";
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
    while (t--) {
        solve();
    }

#ifdef ONLINEJUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC); // this line gives your code runtime
#endif

}