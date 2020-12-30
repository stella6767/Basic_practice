#include <iostream>

using namespace std;






void coloring_BT(int i) {
    int c;
    if (!promising(i)) return;
    if (i == n) {
        output_solution(i);
        exit(0);
    }
    for (c = 1; c <= k; c++) {
        color[i + 1] = c;
        coloring_BT(i + 1);
    }
}

bool promising(int i) {
    int j;
    for (j = 1; j < i; j++)
        if (graph[i][j] && color[i] == color[j]) return false;
    return true;
}


void output_solution() {




}



int main() {




}