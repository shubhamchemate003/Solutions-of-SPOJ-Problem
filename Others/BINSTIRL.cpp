#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL)

void Solve() {
	int N, K; cin >> N >> K;
	cout << (((N - K) & ((K - 1) / 2)) == 0) << endl;
}

signed main() {
	FAST;
#ifndef ONLINE_JUDGE
	freopen("../input1.txt", "r", stdin);
	freopen("../output1.txt", "w", stdout);
#endif

	int tt; cin >> tt; while (tt--)
		Solve();
	return 0;
}