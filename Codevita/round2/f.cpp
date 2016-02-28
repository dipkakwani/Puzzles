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

int dx, dy, r, c;
int heuristic (vector< vector<char> >& map, int i, int j)
{
  if (map[i][j] == 'w')
    return INT_MAX - 1;
  if (map[i][j] == 'd')
    return 0;
  int dix = abs (i - dx);
  int diy = abs (j - dy);
  return dix + diy - min (dix, diy);
}

void find_route (vector< vector<char> >& map, int i, int j, int num)
{
  priority_queue< pair< int, pair<int, int> > > q; 
  pair<int, pair<int, int> > temp (0, pair<int, int> (i, j)); 
  q.push (temp);
  vector<int> a(8, INT_MAX - 1);
  vector< vector<bool> > visited (r, vector<bool> (c));
  vector< vector<char> > map_copy = map;
  while (!q.empty ())
  {
    temp = q.top ();
    q.pop ();
    if (temp.second.first == dx && temp.second.second == dy)
      break;
    visited[temp.second.first][temp.second.second] = true;
    i = temp.second.first;
    j = temp.second.second;
    map_copy[i][j] = 97 + num;
    if (   i + 1 == dx && (j + 1 == dy || j == dy || j - 1 == dy)
        || i - 1 == dx && (j + 1 == dy || j == dy || j - 1 == dy)
        || i == dx && (j + 1 == dy || j - 1 == dy))
        break;
    if (i + 1 < r)
    {
      a[0] = heuristic (map, i + 1, j);
      if (a[0] != INT_MAX - 1 && !visited[i + 1][j])
        q.push (pair<int, pair<int, int> > (-1 * a[0], pair<int, int> (i + 1, j)));
      if (j + 1 < c)
      {
        a[4] = heuristic (map, i + 1, j + 1);
        if (a[4] != INT_MAX - 1 && !visited[i + 1][j + 1])
          q.push (pair<int, pair<int, int> > (-1 * a[4], pair<int, int> (i + 1, j + 1)));
      }
      if (j - 1 >= 0)
      {
        a[5] = heuristic (map, i + 1, j - 1);
        if (a[5] != INT_MAX - 1 && !visited[i + 1][j - 1])
          q.push (pair<int, pair<int, int> > (-1 * a[5], pair<int, int> (i + 1, j - 1)));
      }
    }
    if (i - 1 >= 0)
    {
      a[1] = heuristic (map, i - 1, j);      
      if (a[1] != INT_MAX - 1 && !visited[i - 1][j])
        q.push (pair<int, pair<int, int> > (-1 * a[1], pair<int, int> (i - 1, j)));
      if (j + 1 < c)
      {
        a[6] = heuristic (map, i - 1, j + 1);
        if (a[6] != INT_MAX - 1 && !visited[i - 1][j + 1])
        q.push (pair<int, pair<int, int> > (-1 * a[6], pair<int, int> (i - 1, j + 1)));

      }
      if (j - 1 >= 0)
      {
        a[7] = heuristic (map, i - 1, j - 1);
        if (a[7] != INT_MAX - 1 && !visited[i - 1][j - 1])
        q.push (pair<int, pair<int, int> > (-1 * a[7], pair<int, int> (i - 1, j - 1)));

      }
    }
    if (j + 1 < c)
    {
      a[2] = heuristic (map, i, j + 1);
      if (a[2] != INT_MAX - 1 && !visited[i][j + 1])
        q.push (pair<int, pair<int, int> > (-1 * a[2], pair<int, int> (i, j + 1)));

    }
    if (j - 1 >= 0)
    {
      a[3] = heuristic (map, i, j - 1);
      if (a[3] != INT_MAX - 1 && !visited[i][j - 1])
        q.push (pair<int, pair<int, int> > (-1 * a[3], pair<int, int> (i, j - 1)));

    }
  }
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      if (map_copy[i][j] == 's')
        cout << "- ";
      else
        cout << map_copy[i][j] << " ";
    }
    cout << endl;
  }
}
int main()
{
  int dummy;
  cin >> r >> c;
  vector< vector<char> > map (r, vector<char>(c));
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cin >> map[i][j];
      if (map[i][j]  == 'd')
      {
        dx = i;
        dy = j;
      }
    }
  }
  cin >> dummy;
  int count = 0;
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      if (map[i][j] == 's')
      {
        find_route (map, i, j, count);
        count++;
        cout << endl;
      }
    }
  }
  return 0;
}

