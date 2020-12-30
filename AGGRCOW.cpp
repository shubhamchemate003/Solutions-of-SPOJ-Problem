#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long

int isValid(int pos[], int N, int C, int mid) {
	int cows = 1;
	int prev = 0, mn_dist = INT_MAX;
	for (int i = 0; i < N; i++) {
		if (pos[i] - pos[prev] >= mid) {
			cows++;
			mn_dist = min(mn_dist, pos[i] - pos[prev]);
			prev = i;
		}
	}

	return cows >= C ? mn_dist : -1;
}

int LargestMinDist(int pos[], int N, int C) {
	int left = 0, right = pos[N - 1] - pos[0];
	int ans = -1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		int curr_dist = isValid(pos, N, C, mid);
		if (curr_dist != -1) {
			ans = curr_dist;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	return ans;
}

void Solve() {
	int N, C; cin >> N >> C;
	int pos[N];
	for (int i = 0; i < N; i++)
		cin >> pos[i];

	sort(pos, pos + N);

	cout << LargestMinDist(pos, N, C) << endl;
}

signed main() {
	FAST;
#ifndef ONLINE_JUDGE
	freopen("../input1.txt", "r", stdin);
	freopen("../output1.txt", "w", stdout);
#endif

	int tt; cin >> tt;
	while (tt--)
		Solve();
	return 0;
}