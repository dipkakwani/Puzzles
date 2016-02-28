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
    int n, k;
    bool fl = true;
    cin >> n >> k;
    vector<int> a(n), b(n);
    FOR (i, 1, n + 1)
    {
      a[i - 1] = i;
    }
    FOR (i, 0, n)
      b[(i - k + n) % n] = a[i];

    FOR (i, 0, n)
    {
      if (abs (a[i] - b[i]) < k)
      {
        fl = false;
        break;
      }
    }
    if (fl)
    {
      FOR (i, 0, n)
        cout << b[i] << " ";
      cout << endl;
    }
    else
      cout << "-1\n";
  }
  return 0;
}

