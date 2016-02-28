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
    string s;
    cin >> s;
    int len = s.length ();
    // Left Os and right Zs
    string l_s (s);
    int count1 = 0, count2 = 0;
    for (int i = 0; i < len - 1; i++)
    {
      if (l_s[i] == 'Z' && l_s[i + 1] == 'O')
      {
        swap (l_s[i], l_s[i + 1]);
        count1++;
      }
    }
    // Right Os and left Zs
    string r_s (s);
    for (int i = 0; i < len - 1; i++)
    {
      if (r_s[i] == 'O' && r_s[i + 1] == 'Z')
      {
        swap (r_s[i], r_s[i + 1]);
        count2++;
      }
    }
    cout << min (count1, count2) << endl;
  }
  return 0;
}

