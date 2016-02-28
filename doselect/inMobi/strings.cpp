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
    vector<string> s (n);
    vector<set<char>> st (n);
    FOR (i, 0, n)
    {
      cin >> s[i];
      FOR (j, 0, s[i].length ())
       st[i].insert (s[i][j]);
    }
    vector<vector<int>> freq (n, vi (26));
    FOR (i, 0, n)
    {
      FOR (j, 0, s[i].length ())
        freq[i][s[i][j] - 'a']++;
    }
    
  }
  return 0;
}

