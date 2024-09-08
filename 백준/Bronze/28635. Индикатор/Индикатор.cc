#include <iostream>
using namespace std;

int main() {
    int m, a, b;
    cin >> m >> a >> b;
    
    // 정방향 이동 계산
    int forward_moves = (b - a + m) % m;
    cout << forward_moves << endl;
    
    return 0;
}