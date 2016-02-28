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
  string s, q_type, a, b;
  int n, q;
  getline (cin, a);
  stringstream ip (a);
  ip >> n >> q;
  vi max_row (n), max_col (n);
  FOR (i, 0, q)
  {
    getline (cin, s);
    stringstream inp (s);
    inp >> q_type >> a >> b;
    cout << "type " << q_type << endl;
    cout << "A " << a << " B " << b << endl;
    if (q_type[0] == 'R')
      max_row[stoi (a) - 1] += stoi (b);
    else
      max_col[stoi (a) - 1] += stoi (b);
  }
  cout << max (*max_ele (max_row), *max_ele (max_col)) << endl;
  return 0;
}

