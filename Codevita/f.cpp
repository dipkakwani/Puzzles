#include <bits/stdc++.h>
#include <cmath>
using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> graph;
typedef long long ll;
typedef unsigned long long ull;

void subset_sum (vector<int>& a, int x, int n)
{
  long long comb = (1 << n), sum;
  set< vector<int> > res;
  for (long long i = 1; i < comb; i++)
  {
    vector<int> subset;
    sum = 0;
    for (long long j = 0; j < n; j++)
    {
      if (i & (1 << j))
      {
        subset.push_back (a[j]);
        sum += a[j];
      }
    }
    if (sum == x)
    {
      sort (subset.rbegin (), subset.rend ());
      res.insert (subset);
    }
  }
  vector< vector<int> > result (res.begin (), res.end ());
  sort (result.rbegin (), result.rend ());
  
  for (vector< vector<int> >::iterator it = result.begin (); it != result.end (); it++)
  {
    cout << "[";
    for (vector<int>::iterator i = (*it).begin (); i != (*it).end (); i++)
    {
      if (i ==  (*it).begin ())
        cout << *i;
      else
        cout << ", " << *i;
    }
    if (it != result.end () - 1)
      cout << "]\n";
    else
      cout << "]";
  }
  
}
int main()
{
  int x, n = 0, y;
  vector<int> a;
  string s;
  getline (cin, s);
  cin >> x;
  stringstream in(s);
  while (in >> y)
  {
    a.push_back (y);
    n++;
  }
  subset_sum (a, x, n);
  return 0;
}

