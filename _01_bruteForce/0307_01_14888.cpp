#include <iostream>
#include <limits.h>

using namespace std;

int N, _max, _min;
int A[12], operators[5];

void input() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= 4; i++) cin >> operators[i];
    _max = INT_MIN; // max ambigious
    _min = INT_MAX;
}

int calc(int operand1, int op, int operand2) {
    switch (op) {
    case 1:
        return operand1 + operand2;
    case 2:
        return operand1 - operand2;
    case 3:
        return operand1 * operand2;
    case 4:
        return operand1 / operand2;
    }
}

void rec_func(int k, int val) {
    if (k == N) {   
    // N-1이 아니라 N이었음 -> 나열 문제에서는 마지막에 출력만 해주면 돼서 k = N-1일 때 출력을 했는데, 
    // 이 문제는 마지막 값까지 연산을 해야 한다는 점 !!
        _max = max(_max, val);  
        _min = min(_min, val);
    }
    else {
        for (int cand = 1; cand <= 4; cand++) { // 1: +, 2: -, 3: *, 4: /
            if (operators[cand] != 0) { // 연산자가 남아있는 상태
                operators[cand]--;  // 연산자 하나를 사용 & 재귀 -> 연산자를 다 사용할 때까지 재귀를 하며 사칙연산
                rec_func(k + 1, calc(val, cand, A[k + 1]));    
                // calc(A[k], cand, A[k + 1])로 하게 되면 앞 뒤 값만 계산을 하게 됨
                // 재귀를 통해 앞부터 업데이트 되는 연산을 하나의 value로 보고 연산을 하는 것
                operators[cand]++;  // 재귀 끝나고 새로운 배열로 다시 시작해야 하니까 !!!
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    rec_func(1, A[1]);  // 첫 연산을 위해 A[1]을 매개변수로 넘겨
    cout << _max << "\n" << _min;
    return 0;
}