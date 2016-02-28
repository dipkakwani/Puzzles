#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector< pair<int, int> > a(n);
    map<int, bool> present, subordinate;
    vector<int> id(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
        id[i] = a[i].first;
        present[a[i].first] = true;
    }
    for (int i = 0; i < n; i++)
    {
        if (!a[i].second)
            continue;

        if (present[a[i].second])
            subordinate[a[i].second] = true;
        else
        {
            for (vector<int>::iterator it = id.begin(); it != id.end(); it++)
            {
                if (*it != a[i].first)
                {
                    if (present[a[i].second - *it])
                    {
                        subordinate[*it] = true;
                        subordinate[a[i].second - *it] = true;
                        //cout << a[i].first << " " << a[i].second << endl;
                        //cout << "Subordinate " << *it << " and " << a[i].second - *it << endl;
                        break;
                    }
                }
            }    
        }
    }
    for (vector<int>::iterator it = id.begin(); it != id.end(); it++)
    {
        if (present[*it] && !subordinate[*it])
        {
            cout << *it << endl;
            break;
        }
    }
    return 0;
}
