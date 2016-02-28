#include <bits/stdc++.h>
using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> graph;
typedef long long ll;
typedef unsigned long long ull;

#define print(x) cout << x << endl
#define max_ele(x) max_element(x.begin(), x.end())

int h, w;
void dfs (char board[1001][1001], bool visited[1001][1001], int i, int j, int& count)
{
  visited[i][j] = true;
  if (i + 1 < h)
  {
    if (board[i + 1][j] == '#' && !visited[i + 1][j])
    {
      count++;
      dfs (board, visited, i + 1, j, count);
    }
    if (j + 1 < w && board[i + 1][j + 1] == '#' && !visited[i + 1][j + 1])
    {
      count++;
      dfs (board, visited, i + 1, j + 1, count);
    }
    if (j - 1 >= 0 && board[i + 1][j - 1] == '#' && !visited[i + 1][j - 1])
    {
      count++;
      dfs (board, visited, i + 1, j - 1, count);
    }
  }
  if (i - 1 >= 0)
  {
    if (board[i - 1][j] == '#' && !visited[i - 1][j])
    {
      count++;
      dfs (board, visited, i - 1, j, count);
    }
    if (j + 1 < w && board[i - 1][j + 1] == '#' && !visited[i - 1][j + 1])
    {
      count++;
      dfs (board, visited, i - 1, j + 1, count);
    }
    if (j - 1 >= 0 && board[i - 1][j - 1] == '#' && !visited[i - 1][j - 1])
    {
      count++;
      dfs (board, visited, i - 1, j - 1, count);
    }
  }
  if (j + 1 < w && board[i][j + 1] == '#' && !visited[i][j + 1])
  {
    count++;
    dfs (board, visited, i, j + 1, count);
  }
  if (j - 1 >= 0 && board[i][j - 1] == '#' && !visited[i][j - 1])
  {
    count++;
    dfs (board, visited, i, j - 1, count);
  }
}  
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    cin >> h >> w;
    char board[1001][1001];
    bool visited[1001][1001];
    for (int i = 0; i < h; i++)
    {
      for (int j = 0; j < w; j++)
      {
        visited[i][j] = false;
        cin >> board[i][j];
      }
    }
    int count = 0;
    vi res;
    for (int i = 0; i < h; i++)
    {
      for (int j = 0; j < w; j++)
      {
        if (!visited[i][j] && board[i][j] == '#')
        {
          count = 0;
          dfs (board, visited, i, j, count);
          res.push_back (count);
        }
      }
    }
    sort (res.begin (), res.end ());
    cout << res.size () << endl;
    for (vi::iterator i = res.begin (); i != res.end (); i++)
      cout << *i << " ";
  }
  return 0;
}

