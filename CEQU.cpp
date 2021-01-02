#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long

int gcd(int a, int b) {
	return (b == 0 ? a : gcd(b, a % b));
}

void Solve(int i) {
	int a, b, c; cin >> a >> b >> c;
	int g = gcd(a, b);
	if (c % g == 0)
		cout << "Case " << i << ": Yes\n";
	else
		cout << "Case " << i << ": No\n";
}

signed main() {
	FAST;
#ifndef ONLINE_JUDGE
	freopen("../input1.txt", "r", stdin);
	freopen("../output1.txt", "w", stdout);
#endif

	int tt; cin >> tt;
	for (int i = 1; i <= tt; i++)
		Solve(i);
	return 0;
}