#include <iostream>

using namespace std;

int main() {
	bool S[50] = {0,-4,7};
	if (S[0]) cout << "TRUE"<<endl;
	else cout << "FALSE"<<endl;

	for (int i = 0; i < 50; i++) {
		cout << S[i] << "  ";
	}


	return 0;
}
