#include <bits/stdc++.h>
using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> graph;
typedef long long ll;
typedef unsigned long long ull;

#define FOR(i, x, y) for(auto i = x; i < y; i++)
#define TESTCASE(T) cout << "Case #" << T << ": "
#define print(x) cout << x << endl
#define iterate(i, x) for (auto i = x.begin(); i != x.end(); i++)
#define max_ele(x) max_element(x.begin(), x.end())

int main ()
{
  int t;
  string inp;
  getline (cin, inp);
  stringstream in1 (inp);
  in1 >> t;
  FOR(T, 1, t + 1)
  {
    int n, q;
    getline (cin, inp);
    stringstream in (inp);
    in >> n;
    vector<string> engine (n);
    map<string, int> mp;
    FOR(i, 0, n)
    {
      getline (cin, engine[i]);
      mp[engine[i]] = i;
    }
    vector<bool> seen (n);
    int res = 0;
    getline (cin, inp);
    stringstream in2 (inp);
    in2 >> q;
    FOR(i, 0, q)
    {
      getline (cin, inp);
      bool swit = true;
      FOR(j, 0, n)
      {
        if (!seen[j] && j != mp[inp])
        {
          swit = false;
          break;
        }
      }
      if (swit) 
      {
        res++;
        seen.assign (seen.size (), false);
      }  
      seen[mp[inp]] = true;  
    }
    TESTCASE(T);
    cout << res << endl;
  }
  return 0;
}
