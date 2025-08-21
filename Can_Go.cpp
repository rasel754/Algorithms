#include <bits/stdc++.h>
using namespace std;

char grid[1000][1000];
bool vis[1000][1000];
int n, m;

vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

bool bfs(int si, int sj, int di, int dj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty())
    {
        auto par = q.front();
        q.pop();
        int pi = par.first, pj = par.second;

        if (pi == di && pj == dj)
            return true;

        for (int k = 0; k < 4; k++)
        {
            int ci = pi + d[k].first;
            int cj = pj + d[k].second;

            if (valid(ci, cj) && !vis[ci][cj])
            {
                if (grid[ci][cj] == '.' || grid[ci][cj] == 'B') // walkable
                {
                    q.push({ci, cj});
                    vis[ci][cj] = true;
                }
            }
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    int si, sj, di, dj;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                si = i;
                sj = j;
            }
            if (grid[i][j] == 'B')
            {
                di = i;
                dj = j;
            }
        }
    }

    memset(vis, false, sizeof(vis));

    if (bfs(si, sj, di, dj))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
