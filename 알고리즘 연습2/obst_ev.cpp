#include <iostream>
using namespace std;

float gP[6] = { 0, 0.1, 0.05, 0.15, 0.05, 0.2 };
float gQ[6] = { 0.1, 0.05, 0.05, 0.05, 0.05, 0.15 };
float gPQ[7][6] = { {0.0} };
float gEV[7][6] = { {0.0} };
int gRT[7][6] = { {0} };

float PQ(int i, int j) {
    if (gPQ[i][j] != 0) return gPQ[i][j];
    if (j == i - 1) gPQ[i][j] = gQ[i - 1];
    else gPQ[i][j] = PQ(i, j - 1) + gP[j] + gQ[j];
    return gPQ[i][j];
}

float EV(int i, int j) {
    if (gEV[i][j] != 0) return gEV[i][j];
    if (j == i - 1) {
        gEV[i][j] = gQ[i - 1];
    }
    else {
        float minEV = 1000.0;
        float rEV;
        for (int r = i; r <= j; r++) {
            rEV = EV(i, r - 1) + EV(r + 1, j) + PQ(i, j);
            if (rEV < minEV) minEV = rEV;
        }
        gEV[i][j] = minEV;
    }
    return gEV[i][j];
}

int main() {
    cout << EV(1, 5)<<endl;

    for (int i = 1; i < 7; i++) {
        for (int j = 0; j < 6; j++) cout << gPQ[i][j] << " ";
        cout << endl;
    }
    for (int i = 1; i < 7; i++) {
        for (int j = 0; j < 6; j++) cout << gEV[i][j] << " ";
        cout << endl;
    }
    return 0;
}