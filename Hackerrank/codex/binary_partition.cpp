#include <bits/stdc++.h>
using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> graph;
typedef long long ll;
typedef unsigned long long ull;

#define FOR(i, x, y) for(auto i = x; i < y; i++)
#define TESTCASE(T) cout << "Case #" << T << ": "
#define print(x) cout << x << endl
#define iterate(i, x) for (auto i = x.begin(); i != x.end(); i++)
#define max_ele(x) max_element(x.begin(), x.end())

#define MOD 1000000007
long long dp[100002];

void pre_compute ()
{
  dp[0] = 0;
  dp[1] = 1;
  FOR (i, 1, 50001)
  {
    dp[2 * i] = (dp[2 * i - 1] + dp[i]) % MOD;
    dp[2 * i + 1] = dp[2 * i] % MOD;
  }
}
int main()
{
  int t;
  cin >> t;
  pre_compute ();
  while (t--)
  {
    long long n;
    cin >> n;
    cout << dp[n] << endl;
  }
  return 0;
}

