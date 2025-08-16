#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1000];
bool vis[1000];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while (!q.empty())
    {
        // ber kore niye asbo
        int par = q.front();
        q.pop();

        // ota niye kaj korbo
        cout << par << " ";

        // children gulo push  dibo
        for (int child : adj_list[par])
        {
            if (vis[child] == false)
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
    bfs(0);

    return 0;
}