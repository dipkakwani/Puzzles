#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
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
  ull dp[1000001];
  dp[1] = 1;
  dp[2] = 2;
  FOR (i, 3, 1000001)
    dp[i] = (dp[i - 1] + ((i - 1) * dp[i - 2]) % MOD) % MOD;

  while (t--)
  {
    int n;
    cin >> n;
    cout << dp[n] % MOD << endl;
  }
  return 0;
}

