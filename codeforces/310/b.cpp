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
    int n;
    cin >> n;
    vi a(n);
    FOR(i, 0, n)
        cin >> a[i];
    int active = 0;
    bool flag2 = 0;
    FOR(count, 0, 1000000)
    {
        FOR(i, 0, n)
        {
            if (i % 2)
                a[i] = (a[i] - 1 + n) % n;
            else
                a[i] = (a[i] + 1) % n;
        }
        bool flag1 = 0;
        FOR(i, 0 , n)
        {
            if (a[i] != i)
            {
                flag1 = 1;
                break;
            }
        }
        if (!flag1)
        {
            flag2 = 1;
            cout << "YES\n";
            break;
        }
    }
    if (!flag2)
        cout << "NO\n";
    return 0;
}

