#include <bits/stdc++.h>
using namespace std;
int val[100], wei[100];
int dp[1005][1005];

int knapsack(int i, int mx_weight)
{
    if (i < 0 || mx_weight <= 0)
        return 0;

    if (dp[i][mx_weight] != -1)
        return dp[i][mx_weight];

    if (wei[i] <= mx_weight)
    {
        int opt1 = knapsack(i - 1, mx_weight - wei[i]) + val[i];
        int opt2 = knapsack(i - 1, mx_weight);
        dp[i][mx_weight] = max(opt1, opt2);
        return dp[i][mx_weight];
    }
    else
    {
        dp[i][mx_weight] = knapsack(i - 1, mx_weight);
        return dp[i][mx_weight];
    }
}

int main()
{

    int n, beg;
    cin >> n;
       cin >> beg;

    for (int i = 0; i < n; i++)
    {
        cin>>wei[i];
        cin>>val[i];
    }
    

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= beg; j++)
            dp[i][j] = -1;

    cout << knapsack(n - 1, beg);

    return 0;
}