// 15650
// N과 M (2)
// N 증복 없이, M 고르기

#include <iostream>

using namespace std;

int N, M, selected[9], used[9];

void input() {
    cin >> N;
    cin >> M;
}

void rec_func(int k) {
    if (k == M + 1) {
        for (int i = 1; i <= M; i++) {
            cout << selected[i] << " ";
        }
        cout << "\n";
    }
    else {
        int start = selected[k - 1]; // for 비내림차순
        if (start == 0) start = 1;
        for (int cand = start; cand <= N; cand++) {
            if (used[cand] == 1) continue;  // for 중복 확인
            selected[k] = cand;
            used[cand] = 1;
            rec_func(k + 1);
            selected[k] = 0;
            used[cand] = 0;
        }
        // for (int cand = selected[k-1] + 1; cand <= N; cand++)
        // used 배열 없이 다음 for문 하나로 해결 가능하다고도 함
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    rec_func(1);
    return 0;
}