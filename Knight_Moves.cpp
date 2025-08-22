#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<pair<int, int>> moves = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

bool valid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int bfs(int kx, int ky, int qx, int qy)
{
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;

    dist[kx][ky] = 0;
    q.push({kx, ky});

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        if (x == qx && y == qy)
            return dist[x][y];

        for (auto [dx, dy] : moves)
        {
            int nx = x + dx, ny = y + dy;
            if (valid(nx, ny) && dist[nx][ny] == -1)
            {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return -1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        int kx, ky, qx, qy;
        cin >> kx >> ky;
        cin >> qx >> qy;

        cout << bfs(kx, ky, qx, qy) << "\n";
    }
    return 0;
}
