#include<iostream>
#include<algorithm>

int R, C, A, B;
using namespace std;
int main()
{
	int R, C, A, B;
	cin >> R >> C >> A >> B;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < A; j++)
		{
			for (int k = 0; k < C; k++)
				for (int l = 0; l < B; l++)
				{
					if ((i + k) % 2 == 0)
						cout << "X";
					else cout << ".";
                }
			cout << "\n";
		}
}