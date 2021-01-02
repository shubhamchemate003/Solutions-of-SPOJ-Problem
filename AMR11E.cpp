#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long

int getPrimeFactorCnt(int n) {
	int cnt = 0;
	if (n % 2 == 0)
		cnt++;
	while (n % 2 == 0)
		n /= 2;
	if (n % 3 == 0)
		cnt++;
	while (n % 3 == 0)
		n /= 3;

	for (int i = 5; i * i <= n; i += 6) {
		if (n % i == 0)
			cnt++;
		while (n % i == 0)
			n /= i;

		if (n % (i + 2) == 0)
			cnt++;
		while (n % (i + 2) == 0)
			n /= (i + 2);
	}
	if (n > 3)
		cnt++;
	return cnt;
}

void Solve() {
	int n, k; cin >> n;
	k = 0;
	int i = 30;
	while (true) {
		if (getPrimeFactorCnt(i) >= 3)
			k++;
		if (k == n)
			break;
		i++;
	}
	cout << i << endl;
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