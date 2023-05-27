#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

#define mod(a,b) (((a%b) + b)%b)
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
ll mod = (1e9) + 7;

void solve() {
	int n; cin >> n;
	vi l(n);
	vi r(n);
	vi c(n);

	for (int i = 0; i < n; ++i)
		cin >> l[i] >> r[i] >> c[i];

	ll rmax = INT_MIN;
	ll lmin  = INT_MAX;
	ll lcost = INT_MAX;
	ll rcost = INT_MAX;
	ll scost = INT_MAX;
	for (int i = 0; i < n; ++i) {
		if ((r[i] >= rmax) && (l[i] <= lmin)) {
			if ((r[i] > rmax) && (l[i] < lmin)) {
				rmax = r[i];
				rcost = c[i];
				lmin = l[i];
				lcost = l[i];
				scost = c[i];
			}
			else if (r[i] > rmax) {
				rmax = r[i];
				rcost = c[i];
				lcost = min(lcost, c[i]);

			}
			else if (l[i] < lmin) {

			}
		}
		else if (r[i] > rmax) {

		}
		else if (r[i] == rmax) {

		}
		else if (l[i] < lmin) {

		}
		else if (l[i] == lmin) {

		}

		cout << min(lcost + rcost, scost) << "\n";
	}

}

int main() {

#ifdef ONLINEJUDGE
	clock_t tStart = clock();
	freopen("input.txt", "r", stdin); //can need to change file . this one for taking input
	freopen("output.txt", "w", stdout); // this one for output
#endif
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

#ifdef ONLINEJUDGE
	fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC); // this line gives your code runtime
#endif

	return 0;
}