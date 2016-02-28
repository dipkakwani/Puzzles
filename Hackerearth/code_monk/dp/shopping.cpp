#include <bits/stdc++.h>
using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> graph;
typedef long long ll;
typedef unsigned long long ull;

#define FOR(i, x, y) for (auto i = x; i < y; i++)
#define TESTCASE(T) cout << "Case #" << T << ": "
#define print(x) cout << x << endl
#define iterate(i, x) for (auto i = x.begin(); i != x.end(); i++)
#define max_ele(x) max_element(x.begin(), x.end())

int main ()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int arr[n][3], dp[n][3];
    FOR (i, 0, n)
    {
      cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];

    FOR (i, 1, n)
    {
      dp[i][0] = min (dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
      dp[i][1] = min (dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
      dp[i][2] = min (dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
    }
    cout << min (dp[n - 1][0], min (dp[n - 1][1], dp[n - 1][2])) << endl;
  }
  return 0;
}

