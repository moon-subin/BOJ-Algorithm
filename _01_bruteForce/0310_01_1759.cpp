/*

    중복없이 / 고르는 문제
    cand = selected[k - 1] + 1부터 ..

    int 배열 selected와 char 배열 alpha를 잘 구분했어야 함 
    alpha 배열의 문자를 순서대로 숫자로 대체한 ? ?

*/


#include <iostream>
#include <algorithm>

using namespace std;

int L, C, selected[16];
char alpha[16];
//char vowels[6] = { 'a', 'e', 'i', 'o', 'u' };


void input() {
    cin >> L >> C;
    for (int i = 1; i <= C; i++) cin >> alpha[i];
    sort(alpha + 1, alpha + 1 + C);
}

void rec_func(int k) {
    if (k == L + 1) {
        int vowels_cnt = 0;
        for (int i = 1; i <= L; i++) {
            char c = alpha[selected[i]];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vowels_cnt++;
            }
        }
        if (vowels_cnt >= 1 && vowels_cnt <= L - 2) {
            for (int i = 1; i <= L; i++) {
                cout << alpha[selected[i]];
            }
            cout << "\n";
        }
    }
    else {
        //char start = str[k - 1];
        for (int cand = selected[k - 1] + 1; cand <= C; cand++) {
            //if (used[cand] == 1) continue;
            selected[k] = cand;
            //used[cand] = 1;
            rec_func(k + 1);
            selected[k] = 0;
            //used[cand] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    rec_func(1);
    return 0;
}