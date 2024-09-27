#include <iostream>
using namespace std;

int n, m;
int arr[51];

int main()
{	
	cin >> n >> m;
	if (n == 0) {
		cout << 0 << endl;
		return 0;
	}
    
	for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int res = 0;
	int now = 0;
	for (int i = 0; i < n; i++) {
		if (now + arr[i] <= m) {
            now += arr[i];
        }
        else {
            now = arr[i];
			res++;
		}
	}
	if (now != 0) {
        res++;
    }
    cout << res << endl;
}