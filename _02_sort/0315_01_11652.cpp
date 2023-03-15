#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define SZ 1000001

int N;
long nums[SZ];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> nums[i];
}

void output() {
	sort(nums, nums + N);

	// mode: 최빈값, modeCnt: 최빈값의 등장 횟수, curCnt: 현재값(nums[0])의 등장 횟수
	long mode = nums[0];
	int modeCnt = 1, curCnt = 1;

	for (int i = 1; i < N; i++) {
		if (nums[i] == nums[i - 1]) curCnt++;
		else curCnt = 1;
		if (curCnt > modeCnt) {
			modeCnt = curCnt;
			mode = nums[i];
		}
	}
	cout << mode;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	output();
	return 0;
}