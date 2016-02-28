#include <bits/stdc++.h>
using namespace std;

int main() 
{
  int n;
  int t;
  cin >> t;
  vector<int> a, res;
  a.push_back (1);
  a.push_back (5);
  a.push_back (7);
  a.push_back (10);
  int amount = 1000;
  vector<int> table (amount + 1);
  table[0] = 0;
  int ch = 0;
  for (int i = 1; i <= amount; i++)
  {
    ch = INT_MAX;
    for (int j = 0; j < 4; j++)
    {
      if (i >= a[j])
        ch = min (ch, table[i - a[j]]);
    }
    if (ch < INT_MAX)
      table[i] = ch + 1;
    else
      table[i] = INT_MAX;
  }
  for (int i = 0; i < t; i++)
  {
    cin >> n;    
    cout << table[n];
    if (i != t - 1)
      cout << endl;
  }
  
  return 0;
}
