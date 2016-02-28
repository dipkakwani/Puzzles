#include <bits/stdc++.h>
using namespace std;
int target, n;
bool has_sum(vector<int>& a, int pos, int cur_sum)
{
    if (cur_sum == target)
        return 1;

    if (pos >= n)
        return 0;

    return has_sum(a, pos + 1, cur_sum) || has_sum(a, pos + 1, cur_sum + a[pos]);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> target >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (has_sum(a, 0, 0))
            cout << "YES\n";
        else
            cout << "NO\n";

    }
    return 0;
}
