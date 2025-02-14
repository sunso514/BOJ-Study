#include <iostream>
#include <deque>
using namespace std;


int main(void) {
    int N; cin >> N;
    deque<int> deq;
    for (int i = 0; i < N; i++) deq.push_back(i + 1);

    while (!deq.empty()) {
        cout << deq.front() << " ";
        deq.pop_front();
        if (deq.empty()) break;
        deq.push_back(deq.front());
        deq.pop_front();
    }
}
    