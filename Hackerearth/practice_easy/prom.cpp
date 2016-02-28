#include <bits/stdc++.h>
using namespace std;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> graph;
typedef long long ll;
typedef unsigned long long ull;

#define FOR(i, x, y) for(auto i = x; i < y; i++)
#define TESTCASE(T) cout << "Case #" << T << ": "
#define print(x) cout << x << endl
#define iterate(i, x) for (auto i = x.begin(); i != x.end(); i++)
#define max_ele(x) max_element(x.begin(), x.end())

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        vi boys(m), girls(n);
        FOR(i, 0, m)
            cin >> boys[i];
        FOR(i, 0, n)
            cin >> girls[i];
        sort(boys.begin(), boys.end());
        sort(girls.begin(), girls.end());

        int idx1 = 0, idx2 = 0;
        while (idx1 < m && idx2 < n)
        {
            while (idx2 < n && girls[idx2] >= boys[idx1])
                idx2++;
            if (idx2 == n)
                break;
            idx1++, idx2++;
        }
        if (idx1 == m)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}

