#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long
#define deb1(x) cout << #x << "=" << x << endl;
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl;
#define setBits(x) __builtin_popcountll(x)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932384626
#define MOD 1000000007

const int D = 101;
int ans[D][D];

void PrintMat(int mat[D][D], int N) {
	for (int i = 1; i <= N; i++, cout << endl)
		for (int j = 1; j <= N; j++)
			cout << mat[i][j] << " ";
}

void multMat(int A[D][D], int B[D][D], int M) {
	int res[M + 1][M + 1];
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= M; j++) {
			res[i][j] = 0;
			for (int k = 1; k <= M; k++) {
				res[i][j] += A[i][k] * B[k][j];
				res[i][j] = (res[i][j] % MOD);
			}
		}
	}

	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= M; j++)
			A[i][j] = res[i][j];
}

void MatrixExpo(int A[D][D], int M, int N) {
	for (int i = 1; i <= M; i++) ans[i][i] = 1;

	for (int i = 1; i <= N; i++)
		multMat(ans, A, M);
}

void MatrixExpoFast(int A[D][D], int M, int N) {
	for (int i = 1; i <= M; i++) ans[i][i] = 1;

	while (N > 0) {
		if (N & 1) multMat(ans, A, M);
		N >>= 1;
		multMat(A, A, M);
	}
}

void Solve() {
	memset(ans, 0, sizeof(ans));

	int M, N; cin >> M >> N;
	int A[D][D];
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= M; j++)
			cin >> A[i][j];

	MatrixExpoFast(A, M, N);
	PrintMat(ans, M);
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