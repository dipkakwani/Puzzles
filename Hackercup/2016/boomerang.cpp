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

inline double dist (ii a, ii b)
{
  return abs (sqrt ((a.first - b.first) * (a.first - b.first) +
                    (a.second - b.second) * (a.second - b.second)));
}

int main ()
{
  int t;
  cin >> t;
  FOR (T, 0, t)
  {
    int n;
    ii cord;
    cin >> n;
    vii sky (n);
    long long ans = 0;
    FOR (i, 0, n)
    {
      cin >> cord.first >> cord.second;
      sky[i] = cord;
    }
        
    FOR (i, 0, n)
    {
      unordered_map<double, int> count;
      FOR (j, 0, n)
      {
        if (j != i)
          count[dist (sky[i], sky[j])]++;
      }

      iterate (j, count)
      {
        ans += (*j).second * ((*j).second - 1) / 2;
      }
    }
    
    TESTCASE (T + 1);
    cout << ans << endl;
  }
  return 0;
}

