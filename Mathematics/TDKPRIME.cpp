#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long

const int N = 90000000;
bool isPrime[N + 1];
vector<int> primes;

void SIEVE() {
	for (int i = 2; i <= N; i++) {
		if (!isPrime[i]) {
			primes.push_back(i);
			for (int j = i * i; j <= N; j += i)
				isPrime[j] = 1;
		}
	}
}

void Solve() {
	int k; cin >> k;
	cout << primes[k - 1] << endl;
}

signed main() {
	FAST;
#ifndef ONLINE_JUDGE
	freopen("../input1.txt", "r", stdin);
	freopen("../output1.txt", "w", stdout);
#endif

	SIEVE();
	int tt; cin >> tt; while (tt--)
		Solve();
	return 0;
}