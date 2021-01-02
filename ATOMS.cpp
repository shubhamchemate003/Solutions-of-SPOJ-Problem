#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL)

void Solve() {
	long double N, K, M; cin >> N >> K >> M;
	if (M <= N) {
		cout << 0 << endl;
		return;
	}
	else {
		long double atoms = 1, t = 0;
		while (atoms <= M / N) {
			atoms *= K;
			t++;
		}
		cout << t - 1 << endl;
	}
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