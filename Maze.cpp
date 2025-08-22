#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<string> maze;
vector<vector<bool>> visited;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool dfs(int x, int y, vector<pair<int, int>> &path)
{

    if (maze[x][y] == 'D')
        return true;

    visited[x][y] = true;
    path.push_back({x, y});

    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx >= 0 && nx < N && ny >= 0 && ny < M &&
            !visited[nx][ny] && maze[nx][ny] != '#')
        {
            if (dfs(nx, ny, path))
                return true;
        }
    }

    path.pop_back();
    visited[x][y] = false;
    return false;
}

int main()
{
    cin >> N >> M;
    maze.resize(N);
    visited.assign(N, vector<bool>(M, false));

    int startX = -1, startY = -1;

    for (int i = 0; i < N; i++)
    {
        cin >> maze[i];
        for (int j = 0; j < M; j++)
        {
            if (maze[i][j] == 'R')
            {
                startX = i;
                startY = j;
            }
        }
    }

    vector<pair<int, int>> path;
    if (dfs(startX, startY, path))
    {

        for (auto &cell : path)
        {
            int x = cell.first, y = cell.second;
            if (maze[x][y] != 'R' && maze[x][y] != 'D')
                maze[x][y] = 'X';
        }
    }

    for (auto &row : maze)
        cout << row << endl;

    return 0;
}