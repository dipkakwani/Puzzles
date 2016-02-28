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

int n, m;
ll ans;
vi board (10);
string s;
void n_bishop (int row, int ld, int rd)
{
  if (row == n)
  {
    // cout << "DOne!\n";
    ans++;
    return;
  }
  // s = bitset<3> (ld).to_string ();
  // cout << "LD " << s << endl;
  // s = bitset<3> (rd).to_string ();
  // cout << "RD " << s << endl;
  // s = bitset<3> (board[row]).to_string ();
  // cout << "Board " << s << endl;
  int pos = board[row] & ( ~ (ld | rd));
  // s = bitset<3> (pos).to_string ();
  // cout << "Available position " << s << endl;
  while (pos)
  {
    int p = pos & -pos;
    // s = bitset<3> (p).to_string ();
    // cout << "Placing at col " << s << endl;
    pos -= p;
    n_bishop (row + 1, (ld | p) << 1 & (board[row] << 1), (rd | p) >> 1 & (board[row] >> 1));
  }
}
int main ()
{
  cin >> n >> m;
  FOR (i, 0, n)
  {
    cin >> s;
    FOR (j, 0, m)
      board[i] = board[i] | (((s[j] == '.') ? 1 : 0) << (m - 1 - j));
  }

  // FOR (i, 0, n)
   // cout << board[i] << endl;
  n_bishop (0, 0, 0);
  print (ans);
  return 0;
}
