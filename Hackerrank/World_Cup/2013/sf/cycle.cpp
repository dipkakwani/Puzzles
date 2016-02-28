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

double ans = 0.0;
int cnt[100001];
int c = 0;
void dfs (vector<pair<int, double>>& g, vb& visited, int i, vector<double>& pro)
{
  visited[i] = true;
  if (!visited[g[i].first])
  {
    cnt[i] = c++;
    if (pro.empty ())
    {
      if (g[i].second == 0)
        pro.push_back (0);
      else
        pro.push_back (log10 (g[i].second));
      print (pro.back ());
    }
    else
    {
      if (pro.back () == 0.0)
        pro.push_back (0.0);
      else
        pro.push_back (pro.back () + log10 (g[i].second));
      print (pro.back ());
    }
    dfs (g, visited, g[i].first, pro);
  }
  else
  {
     if (pro.back () == 0.0)
        pro.push_back (0.0);
      else
        pro.push_back (pro.back () + log10 (g[i].second));

    ans += pow (10, pro.back () - pro[cnt[g[i].first]]);
  }
}
int main ()
{
  int n, a;
  double p, ans = 0.0;
  cin >> n;
  vector<pair<int, double>> g (n);
  vector<double> pro (n);
  vb visited (n);
  FOR (i, 0, n)
  {
    cin >> a >> p;
    g[i] = pair<int, double> (a - 1, p);
  }
  FOR (i, 0, n)
  {
    if (!visited[i])
    {
      dfs (g, visited, i, pro);
    }
  }
  printf ("%.2lf\n", ans);
  return 0;
}
