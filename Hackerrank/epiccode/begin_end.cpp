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
    unsigned long long x;
    cin >> x;
    string s;
    cin >> s;
    vector<unsigned long long> occ(26);
    FOR(i, 0, x)
        occ[s[i] - 'a']++;
    unsigned long long res = 0;
    FOR(i, 0, 26)
        res += (occ[i] * (occ[i] + 1)) / 2;
    cout << res << endl;
    return 0;
}

