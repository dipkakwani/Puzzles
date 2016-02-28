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

int main()
{
  int t;
  cin >> t;
  FOR (T, 1, t + 1)
  {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    FOR (i, 0, n)
      cin >> a[i];
    FOR (i, 0, n)
      cin >> b[i];
    sort (a.begin (), a.end ());
    sort (b.rbegin (), b.rend ());
    ll res = 0;
    FOR (i, 0, n)
      res += a[i] * b[i];
    TESTCASE(T);
    cout << res << endl;
  }
  return 0;
}

