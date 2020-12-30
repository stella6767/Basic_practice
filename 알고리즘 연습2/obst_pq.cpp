#include <iostream>
using namespace std;

float gP[6] = { 0, 0.25, 0.05, 0.15, 0.15, 0.10 };
float gQ[6] = { 0.05, 0.05, 0.05, 0.05, 0.05, 0.05 };
float gPQ[7][6] = { {0.0} };
float gEV[7][6] = { {0.0} };
int gRT[7][6] = { {0} };

float PQ(int i, int j) {
	if (gPQ[i][j] != 0) return gPQ[i][j];
	if (j == i - 1) gPQ[i][j] = gQ[i - 1];
	else gPQ[i][j] = PQ(i, j - 1) + gP[j] + gQ[j];
	return gPQ[i][j];
}

	int main() {
		PQ(1, 5); PQ(2, 5); PQ(3, 5);
		PQ(4, 5); PQ(5, 5); PQ(6, 5);
		for (int i = 1; i < 7; i++) {
			for (int j = 0; j < 6; j++) cout << gPQ[i][j] << " ";
			cout << endl;
		}
		return 0;
	}

	//float P[5] = { 0.05, 0.05, 0.05, 0.15, 0.25};
	//float Q[6] = { 0.1, 0.05, 0.05, 0.05, 0.05, 0.15 };
	//
	//float PQ(int i, int j) { //Àç±Í½Ä
	//	if (j < i - 1) return 0.0;
	//	if (j == i - 1) return Q[i - 1];
	//	return PQ(i, j - 1) + P[j] + Q[j];
	//}
	//
	//int main() {
	//	//float prob = 0.0;
	//	//for (int i = 0; i < 6; i++) prob += P[i] + Q[i];
	//	//cout << prob << endl; // ÀüÃ¼ È®År
	//
	//	for (int i = 1; i < 7; i++) {
	//		for (int j = 0; j < 6; j++) cout << PQ(i, j) << " ";
	//		cout << endl;
	//	}
	//	return 0;
	//}