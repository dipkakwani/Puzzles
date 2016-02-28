#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    int a[] = {1, 5, 10, 25, 50};
    while (cin >> n)
    {
        unsigned long long int dp[6][30001];
        for (int i = 0; i <= n; i++)
            dp[0][i] = 0;
        for (int i = 0; i <= 5; i++)
            dp[i][0] = 1;
    
        for (int i = 1; i <= 5; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (j >= a[i - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i][j - a[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        if (dp[5][n] > 1)
        {
            cout << "There are " << dp[5][n] << " ways to produce " << n;
            cout << " cents change." << endl;
        }
        else
        {
            cout << "There is only " << dp[5][n] << " way to produce " << n;
            cout << " cents change." << endl;
        }


    }
    return 0;
}
