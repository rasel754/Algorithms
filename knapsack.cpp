#include <bits/stdc++.h>
using namespace std;
int val[100], wei[100];

int knapsack(int i, int mx_weight)
{
    if (i < 0 || mx_weight <= 0)
        return 0;
    if (wei[i] <= mx_weight)
    {
        int opt1 = knapsack(i - 1, mx_weight - wei[i])+val[i];
        int opt2 = knapsack(i - 1, mx_weight);
        return max(opt1, opt2);
    }
    else
    {
        return knapsack(i - 1, mx_weight);
    }
}

int main()
{
    int n, beg;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> wei[i];
    }
    cin >> beg;

    cout<<knapsack(n - 1, beg);

    return 0;
}