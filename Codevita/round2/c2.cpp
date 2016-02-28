#include <bits/stdc++.h>
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

class disjointSets
{
    map<ii, ii> parent;
public:
    disjointSets(int m, int n)
    {
          for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)   
            parent[ii (i, j)] = ii (i, j);
    }
    ii findSet(ii u)
    {
        return (parent[u] == u)? u : (parent[u] = findSet(parent[u]));
    }
    bool isSameSet(ii u, ii v)
    {
        return (findSet(u) == findSet(v))?1:0;
    }
    void unionSet(ii u, ii v)
    {
        parent[findSet(u)] = findSet(v);
    }
    void res ()
    {
      for (map<ii, ii>::iterator i = parent.begin (); i != parent.end (); i++)
      ;
    }
    void sz ()
    {
      cout << parent.size ();
    }
};
int main()
{
  int t;
  int h, w;
  cin >> t;
      while (t--)
          {

              cin >> h >> w;
            disjointSets d(h, w);
              char board[1001][1001];
              bool visited[1001][1001];
              for (int i = 0; i < h; i++)
              {
                    for (int j = 0; j < w; j++)
                    {
                            cin >> board[i][j];
                          }
                  }
              int count = 0;
              for (int i = 0; i < h; i++)
              {
                for (int j = 0; j < w; j++)
                {
                  if (board[i][j] == '#')
                  {
                    if (i + 1 < h)
                    {
                      if (board[i + 1][j] == '#')
                        d.unionSet (ii (i, j), ii (i + 1, j));
                      if (j + 1 < w && board[i + 1][j + 1] == '#')
                        d.unionSet (ii (i, j), ii (i + 1, j + 1));
                      if (j - 1 >= 0 && board[i + 1][j - 1] == '#')
                        d.unionSet (ii (i, j), ii (i + 1, j - 1));
                    }
                    
                    if (i - 1 >= 0)
                    {

                      if (board[i - 1][j] == '#')
                        d.unionSet (ii (i, j), ii (i - 1, j));
                      if (j + 1 < w && board[i - 1][j + 1] == '#')
                        d.unionSet (ii (i, j), ii (i - 1, j + 1));
                      if (j - 1 >= 0 && board[i - 1][j - 1] == '#')
                        d.unionSet (ii (i, j), ii (i - 1, j - 1));
                    }
                    if (j + 1 < w && board[i][j + 1] == '#')
                    {
                       d.unionSet (ii (i, j), ii (i, j+1));
                    }
                    if (j - 1 >= 0 && board[i][j - 1] == '#')
                    {
                       d.unionSet (ii (i, j), ii (i, j-1));
                    }
                  }
                }
              }
              d.sz ();
          }
    return 0;
}

