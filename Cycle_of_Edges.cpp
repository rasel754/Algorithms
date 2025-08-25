#include <bits/stdc++.h>
using namespace std;

int par[1005];
int group_size[1005];

int find(int node)
{
    if (par[node] == -1)
        return node;
    return par[node] = find(par[node]);
}

void dsu_union(int node1, int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);

    if (leader1 == leader2)
        return;

    if (group_size[leader1] >= group_size[leader2])
    {
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    }
    else
    {
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    memset(par, -1, sizeof(par));
    for (int i = 1; i <= n; i++)
        group_size[i] = 1;

    int cycleEdges = 0;

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;

        int leaderA = find(a);
        int leaderB = find(b);

        if (leaderA == leaderB)
        {

            cycleEdges++;
        }
        else
        {
            dsu_union(a, b);
        }
    }

    cout << cycleEdges << endl;

    return 0;
}
