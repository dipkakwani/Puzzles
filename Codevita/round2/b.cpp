#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> graph;
typedef long long ll;
typedef unsigned long long ull;

#define TESTCASE(T) cout << "Case #" << T << ": "
#define print(x) cout << x << endl
#define max_ele(x) max_element(x.begin(), x.end())

void selsort (vector<string>& a, vector<int>& b, int count)
{
  vector<int>::iterator j = b.begin ();
  vector<string>::iterator k = a.begin ();
  for (int i = 0; i < count; i++)
  {
    if (i & 1)  // Sort numbers
    {
      iter_swap (min_element (j, b.end ()), j);
      j++;
    }
    else    // Sort words
    {
      iter_swap (min_element (k, a.end ()), k);
      k++;
    }
  }
}
int main()
{
  int t;
  cin >> t;
  for (int T = 0; T < t; T++)
  {
    vector<string> a;
    vector<int> b;
    string inp, s, prev;
    int num, i = 0, count;
//    getline (cin, inp, '\n');
//    stringstream in(inp);
    while (cin >> s)
    {
        string::const_iterator k = s.begin();
      if (i & 1)
      {
        num = atoi (s.c_str ());
        b.push_back (num);
      }
      else
      {
        if(isdigit( *k))
        {
            count=atoi(s.c_str());
            break;
        }
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        a.push_back (s);
      }
      i++;
    }
    selsort (a, b, count);
    int idx1 = 0, idx2 = 0, range = 2 * b.size ();
    for (int r = 0; r < range; r++)
    {
      if (r & 1)
      {
        cout << b[idx1] << " ";
        idx1++;
      }
      else
      {
        cout << a[idx2] << " ";
        idx2++;
      }
     }
     if (T != t - 1)
       cout << endl;

  }
  return 0;
}






/*#include<iostream>
using namespace std;



int main()
{
        int n;
        cin>>n;
        while(n--)
        {
            string s;
            cin>>s;
            int st;
            cin>>st;
            cout<<st;
        }
}
*/
