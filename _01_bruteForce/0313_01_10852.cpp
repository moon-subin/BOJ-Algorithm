/*
	vector subscript out of range
*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Student {
	string name;
	int kor, eng, math;
};

bool compareTo(Student a, Student b) {
	if (a.kor == b.kor) {
		if (a.eng == b.eng) {
			if (a.math == b.math) {
				return a.name < b.name;
			}
			return a.math > b.math;
		}
		return a.eng < b.eng;
	}
	return a.kor > b.kor;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	
	vector<Student> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].math;
	}
	sort(v.begin(), v.end(), compareTo);
	for (int i = 0; i < N; i++) cout << v[i].name << "\n";

	return 0;
}