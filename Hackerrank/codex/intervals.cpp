#include <bits/stdc++.h>

using namespace std;

bool comp (const pair<int, int>& a, const pair<int, int>& b)
{
    return (a.second < b.second);
}

int main()
{
    int n, x, y;
    cin >> n;
    vector< pair<int, int> > a (n);
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        a[i] = pair<int, int> (x, y);
    }
    sort (a.begin (), a.end (), comp);
    int fin = a[0].second, res = 1;
    for (int i = 1; i < n; i++)
    {
        if (fin <= a[i].first && fin <= a[i].second)
        {
            res++;
            fin = a[i].second;
        }
    }
    cout << res << endl;
    return 0;
}

