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
  FOR (T, 0, t)
  {
    int n;
    cin >> n;
    ull p;
    cin >> p;
    vector<ull> a (n);
    FOR (i, 0, n)
      cin >> a[i];

    ull cur_sum = 0, idx = 0, ans = 0, run_count = 0;
    bool run = true;

    FOR (i, 0, n)
    {
      if (a[i] <= p)
        ans++;

      if (cur_sum + a[i] > p)
      {
        if (run && cur_sum <= p)
          ans += run_count * (run_count - 1) / 2;
        run = false;
        while (cur_sum + a[i] > p && idx < i)
        {
          cur_sum -= a[idx];
          run_count--;
          if (run_count < 0)
            run_count = 0;
          idx++;
        }
      }
      cur_sum += a[i];
      if (cur_sum <= p)
      {
        run = true;
      }
      run_count++;
    }
    if (run)
      ans += run_count * (run_count - 1) / 2;

    TESTCASE (T + 1);
    cout << ans << endl;
  }
  return 0;
}
