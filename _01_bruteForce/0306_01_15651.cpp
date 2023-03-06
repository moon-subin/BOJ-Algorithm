// 15651
// N과 M (3)
// N 중복 허용, M 순서 나열

#include <iostream>

using namespace std;

int N, M, selected[8];

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

