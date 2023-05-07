#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T, N, M;
vector<long long> A, B;
void setting() { // A, B 배열을 구하고 누적합을 받아놓기
    cin >> N; 
    for (int i = 0; i < N; i++) {
        long long wow; cin >> wow;
        A.push_back(wow);
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        long long wow; cin >> wow;
        B.push_back(wow);
    }
    for (int i = 0; i < N; i++) {
        long long sum = A[i];
        for (int j = i + 1; j < N; j++) {
            sum += A[j];
            A.push_back(sum);
        }
    }
    for (int i = 0; i < M; i++) {
        long long sum = B[i];
        for (int j = i + 1; j < M; j++) {
            sum += B[j];
            B.push_back(sum);
        }
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
}

long long LowerBound(int x) {
    int low = -1, high = B.size();
    while (low + 1 < high) {
        int mid = (low + high) / 2;
        if (B[mid] < x) low = mid;
        else high = mid;
    }
    return high;
}

long long UpperBound(int x) {
    int low = -1, high = B.size();
    while (low + 1 < high) {
        int mid = (low + high) / 2;
        if (B[mid] <= x) low = mid;
        else high = mid;
    }
    return high;
}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(0);
 
    cin >> T; // key값
    setting(); // 배열 관련 입력

    long long ans = 0;
    for (int i = 0; i < A.size(); i++) { // UpperBound - LowerBound = 결정문제의 답이 True로 나오는 범위 크기
        long long low = LowerBound(T - A[i]);
        long long high = UpperBound(T - A[i]);
        ans += high - low;
    }
    cout << ans;

}