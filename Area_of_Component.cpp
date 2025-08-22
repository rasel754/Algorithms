#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
int n, m;

vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    if (grid[i][j] == '-')
        return false;
    return true;
}

int dfs(int i, int j)
{
    vis[i][j] = true;
    int cnt = 1;

    for (auto [di, dj] : d)
    {
        int ci = i + di;
        int cj = j + dj;
        if (valid(ci, cj) && !vis[ci][cj])
        {
            cnt += dfs(ci, cj);
        }
    }
    return cnt;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    memset(vis, false, sizeof(vis));
    int min_area = INT_MAX;
    bool found = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !vis[i][j])
            {
                int area = dfs(i, j);
                min_area = min(min_area, area);
                found = true;
            }
        }
    }

    if (found)
        cout << min_area << "\n";
    else
        cout << -1 << "\n";

    return 0;
}
