#include <bits/stdc++.h>
using namespace std;
int min_element_idx(vector<int>& on)
{
    int idx = 0;
    int min = *(on.begin());
    int min_idx = 0;
    for (auto i = on.begin(); i != on.end(); i++, idx++)
    {
        if (*i < min)
        {
            min_idx = idx;
            min = *i;
        }
    }
    return min_idx;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n, k;
        char x;
        cin >> n >> m >> k;
        vector<int> on(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> x;
                if (x == '*')
                    on[i]++;
            }
        }
        for (int i = 0; i < k; i++)
        {
            x = min_element_idx(on);
            on[x] = (m - on[x]);
        }
        
        int res = 0;
        for (auto i = on.begin(); i != on.end(); i++)
            res += *i;

        cout << res << endl;
    }
    return 0;
}
