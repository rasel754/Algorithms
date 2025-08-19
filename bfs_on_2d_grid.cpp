#include <bits/stdc++.h>
using namespace std;
char grid[1000][1000];
bool vis[1000][1000];
int level[1000][1000];
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;

    return true;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj]=0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int pair_i = par.first;
        int pair_j = par.second;

        // cout << pair_i << " " << pair_j << endl;

        for (int i = 0; i < 4; i++)
        {
            int ci = pair_i + d[i].first;
            int cj = pair_j + d[i].second;

            if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj]=='*')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj]=level[pair_i][pair_j]+1;
            }
        }
    }
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

    int si, sj , di,dj;
    cin >> si >> sj>>di>>dj;

    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    bfs(si, sj);

    cout<<level[di][dj]<<endl;

    return 0;
}