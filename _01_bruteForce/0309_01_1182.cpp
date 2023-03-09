/*

    강의 코드 참고 ..
    언젠간 안 보고 풀 수 있겠지예

    너무 간단하게 풀리는 문제였음
    k번째 원소를 포함할지 말지 결정하는 건 그냥 간단히 재귀 호출해서 .. wow

    정말 진부분집합만 다루는지 확인하기 위해서 S=0일 때 값을 하나 빼주는데 공집합도 집부분집합 아닌가 .. ?

*/

#include <iostream>

using namespace std;

int N, S, cnt = 0;
int nums[21];

void input() {
    cin >> N >> S;
    for (int i = 1; i <= N; i++) cin >> nums[i];
}

void rec_func(int k, int sum) {
    if (k == N + 1) {
        if (sum == S) {
            cnt++;
        }
    }
    else {
        rec_func(k + 1, sum + nums[k]);
        rec_func(k + 1, sum);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    rec_func(1, 0);
    if (S == 0) cnt--;
    cout << cnt;
    return 0;
}

