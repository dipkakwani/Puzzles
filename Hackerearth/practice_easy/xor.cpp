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
    int n, x;
    cin >> n;
    vi a(n);
    FOR(i, 0, n)
        cin >> a[i];
    vi xor_count(150000);
    FOR(i, 0, n)
    {
        x = a[i];
        xor_count[x]++;
        FOR(j, i + 1, n)
        {
            x = x ^ a[j];
            xor_count[x]++;
        }
    }
    int res = 0;
    FOR(i, 0, 4)
    {
        print(xor_count[i]);
        res += (xor_count[i] * (xor_count[i] - 1)) / 2;
    }
    print(res);
    return 0;
}

