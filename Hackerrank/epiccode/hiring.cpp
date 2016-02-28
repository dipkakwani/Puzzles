#include <bits/stdc++.h>
using namespace std;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> graph;

#define FOR(i, x, y) for(auto i = x; i < y; i++)
#define TESTCASE(T) cout << "Case #" << T << ": "
#define print(x) cout << x << endl
#define iterate(i, x) for (auto i = x.begin(); i != x.end(); i++)
#define max_ele(x) max_element(x.begin(), x.end())

int main()
{
    unsigned long long n, p, x;
    cin >> n >> p >> x;
    vi a(n);
    unsigned long long mx = 0, mx_idx = 0;
    FOR (i, 0, n)
    {
        cin >> a[i];
        if (mx < a[i] * p)
        {
            mx = a[i] * p;
            mx_idx = i + 1;
        }
        p -= x;
    }
    cout << mx_idx << endl;

    return 0;
}

