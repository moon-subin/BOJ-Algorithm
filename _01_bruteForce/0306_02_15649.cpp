// 15649
// N과 M (1)
// N 증복 없이, M 순서 나열

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
        for (int cand = 1; cand <= N; cand++) {
            if (used[k] == 1) continue; // 이미 쓰였으면 넘어가기
            selected[k] = cand;
            used[k] = 1;    // 사용한 후 1로
            rec_func(k+1);
            selected[k] = 0;
            used[k] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    rec_func(1);
    return 0;
}