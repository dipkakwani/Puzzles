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
    ull k;
    int n;
    cin >> n >> k;
    vector<ll> h1(n), h2(n);
    FOR(i, 0, n)
        cin >> h1[i];
    FOR(i, 0, n)
        cin >> h2[i];
    sort(h1.begin(), h1.end());
    sort(h2.begin(), h2.end());
    int idx1 = 0, idx2 = 0;
    ull res = 0;
    while (idx1 < n && idx2 < n)
    {
        if (abs(h1[idx1] - h2[idx2]) <= k)
        {
            res++;
            idx1++, idx2++;
        }
        else if (h1[idx1] > h2[idx2])
            idx2++;
        else
            idx1++;
    }
    cout << res << endl;
    return 0;
}

