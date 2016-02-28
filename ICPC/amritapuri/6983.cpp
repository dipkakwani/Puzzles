#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, t;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> t;
            a[i] = t;
        }
        sort(a.begin(), a.end());
        bool flag = false;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] == a[i + 1])
            {
                flag = true;
                break;
            }
        }
        if (flag)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}
