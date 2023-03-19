/*
    https://t-okk.tistory.com/121 보고 공부 
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T, N;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int ans = 0;
		cin >> N;
		int* L = new int[N];
		for (int j = 0; j < N; j++) {
			cin >> L[j];
		}
		sort(L, L + N);
		for (int k = 2; k < N; k++) {
			int sub = L[k] - L[k - 2];
			ans = max(ans, sub);
		}
		cout << ans << "\n";
	}
	return 0;
}
