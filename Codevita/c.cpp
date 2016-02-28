#include <bits/stdc++.h>
using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> graph;
typedef long long ll;
typedef unsigned long long ull;

bool has_sum (vector<int>& a, int x, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      for (int k = j + 1; k < n; k++)
      {
        if (a[i] + a[j] + a[k] == x)
          return true;
      }
    }
  }
  return false;
}
int main()
{
  int n, x;
  cin >> n;
  vector<int> a (n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  cin >> x;
  if (has_sum(a, x, n))
    cout << "True";
  else
    cout << "False";
  return 0;
}

