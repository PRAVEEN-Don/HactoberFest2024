#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int x, int y, vector<vector<int>>& maze, vector<vector<int>>& solution, int N) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && solution[x][y] == 0);
}

bool solveMazeUtil(int x, int y, vector<vector<int>>& maze, vector<vector<int>>& solution, int N) {
    if (x == N - 1 && y == N - 1) {
        solution[x][y] = 1;
        return true;
    }

    if (isSafe(x, y, maze, solution, N)) {
        solution[x][y] = 1;

        if (solveMazeUtil(x, y + 1, maze, solution, N))
            return true;

        if (solveMazeUtil(x + 1, y, maze, solution, N))
            return true;

        if (solveMazeUtil(x, y - 1, maze, solution, N))
            return true;

        if (solveMazeUtil(x - 1, y, maze, solution, N))
            return true;
        solution[x][y] = 0;
        return false;
    }

    return false;
}

bool solveMaze(vector<vector<int>>& maze, int N) {
    vector<vector<int>> solution(N, vector<int>(N, 0));

    if (!solveMazeUtil(0, 0, maze, solution, N)) {
        cout << "No path exists in the maze" << endl;
        return false;
    }

    cout << "The path is: " << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
    return true;
}

int main() {
    int N;
    cout << "Enter the size of the maze (N): ";
    cin >> N;

    vector<vector<int>> maze(N, vector<int>(N));

    cout << "Enter the maze matrix (1 for open path, 0 for blocked):" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> maze[i][j];
        }
    }

    solveMaze(maze, N);
    return 0;
}
