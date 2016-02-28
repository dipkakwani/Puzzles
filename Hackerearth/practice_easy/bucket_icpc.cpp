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
        int n, k;
        cin >> n >> k;
        string s;
        vi bucket(101);
        FOR(i, 0, n)
        {
            cin >> s;
            bucket[s.length()]++;
        }
        int count = 0;
        bool flag = true;
        FOR(i, 0, 101)
        {
            if (bucket[i])
            {
                count += (bucket[i] / k);
            }
            if (bucket[i] && (bucket[i] % k))
            {
                flag = false;
                break;
            }
        }
        if (flag && count == (n / k))
            cout << "Possible\n";
        else
            cout << "Not possible\n";
    }
    return 0;
}

