/*

    결국 패스트캠퍼스 강의 참고 .....
    서로 공격하는 퀸이 없는 경우를 확인하는 함수를 만들어야 했는데
    이중 for문에서 j의 범위를 N까지로 함 ..
    왜 i 전까지인지 ..

    시간초과 .. 강의에서 >>불가능한 위치에 애초에 두지 말자<<
    공격가능한지 확인하는 코드를 따로 빼서 함수로 ..

    너무너무어렵네예 .............

*/

#include <iostream>

using namespace std;

int N, * col, cnt = 0;

void input() {
    cin >> N;
    col = new int[N];
}

bool attacktable(int r1, int c1, int r2, int c2) {
    if (r1 == r2 || c1 == c2) return true;
    else if (r1 + c1 == r2 + c2) return true;
    else if (r1 - c1 == r2 - c2) return true;
    else return false;
}

bool unableToAttack() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {   // N까지 안 감
            if (attacktable(i, col[i], j, col[j])) return false;
        }
    }
    return true;
}

void rec_func(int row) {
    if (row == N + 1) {
        if (unableToAttack()) {
            cnt++;
        }
    }
    else {
        for (int c = 1; c <= N; c++) {
            bool possible = true;
            for (int i = 1; i < row; i++) {
                if (attacktable(i, col[i], row, c)) {
                    possible = false;
                    break;
                }
            }
            if (possible) {
                col[row] = c;
                rec_func(row + 1);
                col[row] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    rec_func(1);
    cout << cnt;
    return 0;
}
