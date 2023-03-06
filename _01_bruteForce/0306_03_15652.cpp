// 15652
// N과 M (4)
// N 증복 허용, M 고르기

#include <iostream>

using namespace std;

int N, M, selected[9];

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
        int start = selected[k - 1]; // 앞 배열의 숫자보다 크거가 같아야 하므로 2 4 다음 3 3 (3 1 x, 3 2 x)
        if (start == 0) start = 1;
        for (int cand = start; cand <= N; cand++) {
            selected[k] = cand;
            rec_func(k + 1);
            selected[k] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    rec_func(1);
    return 0;
}