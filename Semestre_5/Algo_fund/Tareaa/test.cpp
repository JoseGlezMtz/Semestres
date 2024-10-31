#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int M, N;
vector<vector<int>> maze, solution;
vector<vector<int>> bestSolution;
int minPathLength = INT_MAX;

bool isValid(int x, int y) {
    return (x >= 0 && x < M && y >= 0 && y < N && maze[x][y] == 1);
}

// Backtracking
bool solveMazeBacktracking(int x, int y) {
    if (x == M - 1 && y == N - 1) { // Llegamos al destino
        solution[x][y] = 1;
        return true;
    }
    if (isValid(x, y)) {
        solution[x][y] = 1;
        
        if (solveMazeBacktracking(x + 1, y)) return true;  // Abajo
        if (solveMazeBacktracking(x, y + 1)) return true;  // Derecha
        if (solveMazeBacktracking(x - 1, y)) return true;  // Arriba
        if (solveMazeBacktracking(x, y - 1)) return true;  // Izquierda
        
        solution[x][y] = 0; // Deshacer la marca si no hay camino
        return false;
    }
    return false;
}

// branch and bound
void solveMazeBranchAndBound(int x, int y, int pathLength) {
    if (x == M - 1 && y == N - 1) {
        solution[x][y] = 1;
        if (pathLength < minPathLength) { // Si encuentra una mejor solucion
            minPathLength = pathLength;
            bestSolution = solution;
        }
        solution[x][y] = 0;
        return;
    }
    if (isValid(x, y)) {
        solution[x][y] = 1;

        if (pathLength + 1 < minPathLength) solveMazeBranchAndBound(x + 1, y, pathLength + 1); // Abajo
        if (pathLength + 1 < minPathLength) solveMazeBranchAndBound(x, y + 1, pathLength + 1); // Derecha
        if (pathLength + 1 < minPathLength) solveMazeBranchAndBound(x - 1, y, pathLength + 1); // Arriba
        if (pathLength + 1 < minPathLength) solveMazeBranchAndBound(x, y - 1, pathLength + 1); // Izquierda

        solution[x][y] = 0; // Deshacer la marca si no hay camino (poda)
    }
}

void printSolution(const vector<vector<int>>& sol) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cin >> M >> N;
    maze.resize(M, vector<int>(N));
    solution.resize(M, vector<int>(N, 0));
    bestSolution.resize(M, vector<int>(N, 0));

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> maze[i][j];
        }
    }

    cout << "backtracking:" << endl;
    if (solveMazeBacktracking(0, 0)) {
        printSolution(solution);
    } else {
        cout << "no" << endl;
    }

    solution.assign(M, vector<int>(N, 0));
    minPathLength = INT_MAX;

    cout << "\nbranch and bound:" << endl;
    solveMazeBranchAndBound(0, 0, 0);
    if (minPathLength < INT_MAX) {
        printSolution(bestSolution);
    } else {
        cout << "no" << endl;
    }

    return 0;
}