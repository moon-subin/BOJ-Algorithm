#include <iostream>
#include <algorithm>

using namespace std;

int N, M, idx = 1;
int selected[9], nums[9];
bool used[9];

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> nums[i];
}

void deduplication(int* arr) {
	bool new_arr[10000] = { false };
	for (int i = 1; i <= N; i++) {
		if (new_arr[arr[i]] == true) continue;
		else {
			new_arr[arr[i]] = true;
			arr[idx] = arr[i];
			idx++;
		}
	}
}

void rec_func(int k) {
	if (k == M + 1) {
		for (int i = 1; i <= M; i++) {
			cout << selected[i] << " ";
		}
		cout << "\n";
	}
	else {
		int prev_num = -1;
		for (int cand = 1; cand <= N; cand++) {
			if (!used[cand] && prev_num != nums[cand]) {
				selected[k] = nums[cand];
				used[cand] = true;
				prev_num = nums[cand];
				rec_func(k + 1);
				used[cand] = false;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	sort(nums + 1, nums + 1 + N);
	rec_func(1);
	return 0;
}