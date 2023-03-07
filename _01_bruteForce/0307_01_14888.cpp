/*

    N과 M 예제만을 학습하고 응용 문제를 풀기가 매우 어려웠음
    필요한 배열이 무엇인지 떠오르지도 않았음 .. ㅜ
    결국 강의 자료를 참고해버림 ^^

    다른 사람들의 코드 풀이를 찾아보는데 기본적으로 DFS 문제임을 염두해두고 풀이를 시작함
    
    백트래킹(완전탐색)의 응용예제로 나온 문제이므로 단순히 해당 알고리즘을 활용해야 하는구나 정도로 생각하고
    어떤 이유에서 백트래킹이라는 알고리즘이 필요한지 생각해보지 않았 /...
    백트래킹의 대표적인 예가 재귀 호출 / 스택을 통한 DFS라는 것도 몰라서 매개변수를 무엇으로 받아와야 하는지에 대한 감이 없었음

    알고리즘 개념을 확실히 하는 것이 중요 !!

*/


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