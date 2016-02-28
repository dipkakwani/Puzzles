#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a[i] = x;
    }
    sort(a.begin(), a.end());
    int res = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] >= a[i + 1])
        {
            res += (a[i] - a[i + 1] + 1);
            a[i + 1] = (a[i] + 1);
        }
    }
    cout << res << endl;
    return 0;
}
