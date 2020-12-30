#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long

int getSum(int N) {
	return (N * (N + 1)) / 2;
}

int getPratasNumber(int rank, int time) {
	return (pow(1 + (8 * time / rank), 0.5) - 1) / 2;
}

bool isValid(int arr[], int L, int P, int mid) {
	int cnt = 0;
	for (int i = 0; i < L; i++)
		cnt += getPratasNumber(arr[i], mid);

	return cnt >= P;
}

int MinTime(int arr[], int L, int P) {
	int left = 0, right = arr[L - 1] * getSum(P);
	int mn_time = INT_MAX;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (isValid(arr, L, P, mid)) {
			mn_time = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	return mn_time;
}

void Solve() {
	int P, L; cin >> P >> L;
	int arr[L];
	for (int i = 0; i < L; i++)
		cin >> arr[i];

	sort(arr, arr + L);

	cout << MinTime(arr, L, P) << endl;
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