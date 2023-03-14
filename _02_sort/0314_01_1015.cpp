/*
	패스트캠퍼스 강의자료 클론코딩

    어이없는 오류 >> #define ~~ ; << 세미콜론을찍고난리

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define SZ 51

int N;

struct Elem {
	int num, idx;
	bool operator<(Elem& other) {
		if (num != other.num) return num < other.num;
		return idx < other.idx;
	}
}B[SZ];

int P[SZ];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		B[i] = { x, i };
	}
}

void output() {
	sort(B, B + N);
	for (int i = 0; i < N; i++) P[B[i].idx] = i;
	for (int i = 0; i < N; i++) cout << P[i] << " ";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	output();
	return 0;
}