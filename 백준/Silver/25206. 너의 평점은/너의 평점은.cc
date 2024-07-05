#include <iostream>

using namespace std;

int main() {

  string N, G;
  double C;
  double sum = 0.0;
  double temp;
  double ans = 0.0;
  for(int i = 0; i < 20; i++) {
    cin >> N >> C >> G;
    if(G == "P") continue;
    sum += C;
    if(G == "F") continue;
    if(G[0] == 'A') temp = 4;
    else if (G[0] == 'B') temp = 3;
	else if (G[0] == 'C') temp = 2;
    else temp = 1;

    if (G[1] == '+') temp += 0.5;

    ans += C * temp;
  }
  cout << ans / sum;

  return 0;
}