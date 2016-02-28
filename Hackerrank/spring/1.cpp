#include <bits/stdc++.h>
using namespace std;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> graph;
#define FOR(i, x, y) for(auto i = x; i < y; i++)
#define TESTCASE(T) cout << "Case #" << T << ": ";
#define print(x) cout << x << endl;
#define iterate(i, x) for (auto i = x.begin(); i != x.end(); i++)
#define max_ele(x) max_element(x.begin(), x.end())
int main()
{
    int n;
    cin >> n;
    vi a(n);
    FOR(i, 0, n)
        cin >> a[i];
    sort(a.begin(), a.end());
    int q, x;
    cin >> q;
    while (q--)
    {
        cin >> x;
        int res = lower_bound(a.begin(), a.end(), x) - a.begin();
        cout << res << endl;
    }

    return 0;
}

