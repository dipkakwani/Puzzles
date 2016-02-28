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

int main()
{
  double a, d, det1, x1, x2, y1, y2;
  cin >> a >> d;
  if (a <= 0 || a > 57 * d || d <= 0 || d > 1.7 * a)
  {
    printf ("Invalid Input\n");
    return 0;
  }
  det1 = 36 * a * a - 12 * (3 * a * a - d * d);
  /*if (det1 < 0)
  {
    cout << "Invalid Input\n";
    return 0;
  }*/
  if (det1 < 0)
    det1 = 0;
  det1 = sqrt (det1);
  x1 = (6 * a - det1) / 6;
  x2 = (6 * a + det1) / 6;
  /*if (x1 > a && x2 > a)
  {
    cout << "Invalid Input\n";
    return 0;
  }*/
  y1 = (d * d + (a - x1) * (a - x1));
  y2 = (d * d + (a - x2) * (a - x2));
  /*if (y1 < 0 && y2 < 0)
  {
    cout << "Invalid Input\n";
    return 0;
  }*/
  if (y1 >= 0)
    y1 = sqrt (y1);
  if (y2 >= 0)
    y2 = sqrt (y2);
  if (x1 <= a && x1 >= 0 && x2 <= a && x2 >=0)
  {
    if (y1 < 0)
    {
      printf ("X = %.11lf\n", x2);
      printf ("Y = %.11lf\n", y2);
    }
    else if (y2 < 0)
    {
      printf ("X = %.11lf\n", x1);
      printf ("Y = %.11lf\n", y1);
    }
    else if (y1 > y2)
    {
      printf ("X = %.11lf\n", x2);
      printf ("Y = %.11lf\n", y2);
    }
    else
    {
      printf ("X = %.11lf\n", x1);
      printf ("Y = %.11lf\n", y1);
    }
  }
  else
  {  
    if (x1 <= a && x1 >= 0)
    {
      if (y1 < 0)
      {
        cout << "Invalid Input\n";
        return 0;
      }
      printf ("X = %.11lf\n", x1);
      printf ("Y = %.11lf\n", y1);
    }
    else if (x2 <= a && x2 >= 0)
    {
      if (y1 < 0)
      {
        cout << "Invalid Input\n";
        return 0;
      }
      printf ("X = %.11lf\n", x2);
      printf ("Y = %.11lf\n", y2);
    }
    else
      cout << "Invalid Input\n";
  }
  return 0;
}

