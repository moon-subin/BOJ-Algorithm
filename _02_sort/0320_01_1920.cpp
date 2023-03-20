/*

    모든 정수의 범위는 -2^31 보다 크거나 같고 2^31보다 작다.
    => long ?

    배열 A[N] 정렬..
    배열 B[M] 정렬

    생각나는 게 딱 봐도 시간초과일듯 ...


    런타임 에러 segfault

    int* B = new int[M] << 동적할당 이게 문제였음

*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int N, M;
int A[100001];

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
}

void pro(int n) {
    int low = 0;
    int high = N - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (A[mid] == n) {
            cout << '1' << "\n";
            return;
        }
        else if (A[mid] < n) low = mid + 1;
        else if (A[mid] > n) high = mid - 1;
    }
    cout << '0' << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    sort(A, A + N);
    cin >> M;
    for (int i = 0; i < M; i++) {
        int b;
        cin >> b;
        pro(b);
    }
    return 0;
}