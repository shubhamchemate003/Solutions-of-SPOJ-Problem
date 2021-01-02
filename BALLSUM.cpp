#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

void Solve() {
	while (true) {
		int N, K; cin >> N >> K;
		if (N == -1 && K == -1)
			break;

		int deno = N * (N - 1) / 2;
		int num = ((K - 2) / 2) * ((K - 2) / 2 + 1);

		if (K & 1)
			num += K / 2;

		if (num == 0) {
			cout << 0 << endl;
			continue;
		}
		if (num == deno) {
			cout << 1 << endl;
			continue;
		}

		int g = gcd(num, deno);
		num /= g;
		deno /= g;
		cout << num << "/" << deno << endl;
	}
}

signed main() {
	FAST;
#ifndef ONLINE_JUDGE
	freopen("../input1.txt", "r", stdin);
	freopen("../output1.txt", "w", stdout);
#endif

	// int tt; cin >> tt; while (tt--)
	Solve();
	return 0;
}