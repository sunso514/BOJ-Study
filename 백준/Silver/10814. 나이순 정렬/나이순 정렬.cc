#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <map>
#include <deque>
#include <set>
#include <tuple>


#define endl "\n"
#define FOR(a, b) for(int (a) = 0; (a) < (b); (a)++)

using namespace std;

int N, M;

struct Data {
	int index, age;
	string name;
};


bool compare(Data& a, Data& b) {
	if (a.age != b.age) {
		return a.age < b.age;
	}
	return a.index < b.index;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;
	vector<Data> vec(N);

	for (int i = 0; i < N; i++) {
		cin >> vec[i].age >> vec[i].name;
		vec[i].index = i;
	}
	sort(vec.begin(), vec.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << vec[i].age << " " << vec[i].name << endl;
	}

}