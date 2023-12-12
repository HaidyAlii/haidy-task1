#include <bits/stdc++.h>
using namespace std;

#define ROW 5
#define COL 5

// Direction vectors
int dRow[] = { -1, 0, 0, 1 };  // Up, Right, Left, Down
int dCol[] = { 0, 1, -1, 0 };

bool isValid(bool vis[][COL], int row, int col, vector<vector<int>>& grid)
{
    // If cell lies out of bounds or is an obstacle
    if (row < 0 || col < 0 || row >= ROW || col >= COL || grid[row][col] == -1)
        return false;

    // If cell is already visited
    if (vis[row][col])
        return false;

    // Otherwise
    return true;
}

// Function to perform the BFS traversal
void BFS(vector<vector<int>>& grid, bool vis[][COL], int startRow, int startCol, int goalRow, int goalCol, vector<pair<int, int>>& path)
{
    queue<pair<int, int>> q;
    q.push({startRow, startCol});

    // Parent information to reconstruct the path
    map<pair<int, int>, pair<int, int>> parent;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        int x = current.first;
        int y = current.second;

        // Check if the current cell is the goal
        if (x == goalRow && y == goalCol) {
            // Reconstruct the path using parent information
            while (x != startRow || y != startCol) {
                path.push_back({x, y});
                pair<int, int> p = parent[{x, y}];
                x = p.first;
                y = p.second;
            }
            path.push_back({startRow, startCol});
            reverse(path.begin(), path.end());
            return;
        }

        // Mark the current cell as visited
        vis[x][y] = true;

        // Explore the adjacent cells with BFS
        for (int i = 0; i < 4; i++) {
            int adjx = x + dRow[i];
            int adjy = y + dCol[i];

            if (isValid(vis, adjx, adjy, grid)) {
                q.push({adjx, adjy});
                parent[{adjx, adjy}] = {x, y};
            }
        }
    }

    // If no path found to the goal
}

// Driver Code
int main()
{
    // Given input matrix with obstacles represented by -1
    vector<vector<int>> grid = {
        { -1, 2, 3, 4, 5 },
        { 6, 7, 8, 9, -1 },
        { -1, 12, 13, 14, 15 },
        { 16, 17, 18, 19, -1 },
        { -1, 22, 23, 24, 25 }
    };

    // Declare the visited array and path
    bool vis[ROW][COL];
    memset(vis, false, sizeof vis);
    vector<pair<int, int>> path;

    // Define start and goal points
    int startRow = 3, startCol = 0;
    int goalRow = 0, goalCol = 4;

    BFS(grid, vis, startRow, startCol, goalRow, goalCol, path);

    if (!path.empty()) {
        cout << "Shortest path to the goal:" << endl;
        for (const auto& p : path) {
            cout << grid[p.first][p.second] << " ";
        }
        cout << endl;
    } else {
        cout << "No path found to the goal." << endl;
    }

    return 0;
}
