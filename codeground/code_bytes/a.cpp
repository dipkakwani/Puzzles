#include <bits/stdc++.h>
using namespace std;
int main () {
    int n, c, t, x;
    cin >> n >> c;
    bool want[c][1001];
    int dp[c][1001];
    for (int i = 0; i < c; i++)
    {
        cin >> t;
        for (int j = 0; j < t; j++)
        {
            cin >> x;
            want[i][x - 1] = 1;
        }

    }
    for (int i = 0; i < 1000; i++)
        dp[0][i] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            if (want[i][j])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] + 1;
        }
    }
    int mn = 9999999;
    for (int i = 0; i < n; i++)
        mn = min(mn, dp[c - 1][i]);
    cout << mn << endl;
    return 0;
}
