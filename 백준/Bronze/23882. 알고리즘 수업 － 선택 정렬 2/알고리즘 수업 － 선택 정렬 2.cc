#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, k; cin >> n >> k; int v[n], I[n], R[n];
	for (int i = 0; i < n; i++) {cin >> v[i]; I[i] = v[i]; } 
sort(I, I + n); for (int i = 0; i < n; i++) R[v[i] = lower_bound(I, I + n, v[i]) - I] = i;
	for (int i = n - 1; i >= 0 && k; i--) { if (R[i] ^ i) { R[v[R[i]] = v[i]] = R[i]; v[i] = i;--k; } }
	if (k) cout << "-1"; else for (int i : v) cout << I[i] << " ";
}