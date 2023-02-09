#include <iostream>
#include <cstring>
using namespace std;

int main() {
	
	int n = 0;
	while (true) {
		char sentence[256];
		cin.getline(sentence, 256, '\n');
		n = 0;
		for (int c = 0; c < strlen(sentence); c++) {
			if (sentence[c] == 'A' || sentence[c] == 'a' || sentence[c] == 'e' || sentence[c] == 'E' || sentence[c] == 'i' || sentence[c] == 'I' || sentence[c] == 'O' || sentence[c] == 'o' || sentence[c] == 'u' || sentence[c] == 'U') {
				n++;
			}
			else if (sentence[c] == '#') {
				return 0;
			}
		}
		cout << n << "\n";
	}

}