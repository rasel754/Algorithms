#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[10000];
bool vis[10000];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int child : adj_list[par])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
            }
        }
    }
};

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));

    int src, des;
    cin >> src >> des;

    bfs(src);

    if (vis[des])
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}