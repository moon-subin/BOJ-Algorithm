/*
    감이 안 잡혀서 강의자료 클론코딩 함 ..
    근데 막상 타이핑 하고 찬찬히 보는데 생각보다 간단한 느낌 ..
    붙잡고 풀어보는 연습을 많이 해야 할듯
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define SZ 5001

int N;
vector<int> dot[SZ];

void input() {
	cin >> N;
	int coord, color;
	for (int i = 0; i < N; i++) {
		cin >> coord >> color;
		// TODO: color인 색깔의 점이 coord에 놓여있음
		dot[color].push_back(coord);
	}
}

int toLeft(int color, int x) {
	if (x == 0) return 0x7fffffff;
	else return dot[color][x] - dot[color][x - 1];
}

int toRight(int color, int x) {
	if (x + 1 == dot[color].size()) return 0x7fffffff;
	else return dot[color][x + 1] - dot[color][x];
}

void output() {
	int ans = 0;
	for (int color = 1; color <= N; color++) {
		// TODO: 색깔별로, 각 점마다 가장 가까운 점 찾아주기
		sort(dot[color].begin(), dot[color].end());
		for (int i = 0; i < dot[color].size(); i++) {
			int left = toLeft(color, i);
			int right = toRight(color, i);
			ans += min(left, right);
		}
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	output();
	return 0;
}