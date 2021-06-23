#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long

bool isValid(int arr[], int N, int M, int mid) {
	int wood = 0;
	for (int i = 0; i < N; i++)
		if (arr[i] > mid)
			wood += arr[i] - mid;
	return wood >= M;
}

int getMaxHeight(int arr[], int N, int M) {
	int left = 0, right = arr[N - 1];
	int H = -1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (isValid(arr, N, M, mid)) {
			H = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	return H;
}

void Solve() {
	int N, M; cin >> N >> M;
	int arr[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);
	cout << getMaxHeight(arr, N, M) << endl;
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