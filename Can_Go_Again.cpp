#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<vector<long long>> adj_mat(n + 1, vector<long long>(n + 1, INF));

    for (int i = 1; i <= n; i++)
        adj_mat[i][i] = 0;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_mat[a][b] = min(adj_mat[a][b], (long long)c);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adj_mat[i][k] < INF && adj_mat[k][j] < INF)
                {
                    adj_mat[i][j] = min(adj_mat[i][j], adj_mat[i][k] + adj_mat[k][j]);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (adj_mat[i][i] < 0)
        {
            cout << "Negative Cycle Detected" << endl;
            return 0;
        }
    }

    int S;
    cin >> S;

    int T;
    cin >> T;
    while (T--)
    {
        int D;
        cin >> D;
        if (adj_mat[S][D] == INF)
            cout << "Not Possible" << endl;
        else
            cout << adj_mat[S][D] << endl;
    }

    return 0;
}
