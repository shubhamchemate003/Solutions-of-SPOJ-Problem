#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long

bool isPrime(int n) {
	if (n == 1)
		return false;
	if (n == 2 || n == 3)
		return true;
	if (n % 2 == 0 || n % 3 == 0)
		return false;
	for (int i = 5; i * i <= n; i += 5) {
		if (n % i == 0)
			return false;
		if (n % (i + 1) == 0)
			return false;
	}
	return true;
}

void Solve() {
	int n; cin >> n;
	int F[n + 1];
	F[0] = 0, F[1] = 1, F[2] = 2;
	for (int i = 3; i <= n; i++) {
		if ((i & 1) && isPrime(i))
			F[i] = 0;
		else {
			int a = sqrt(i);
			while (i % a)
				a--;
			int b = i / a;
			F[i] = F[a] + F[b];
		}
	}
	cout << F[n] << endl;
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