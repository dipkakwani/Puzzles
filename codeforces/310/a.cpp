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
    int l, ones = 0, zeroes = 0;
    cin >> l;
    string s;
    cin >> s;
    for (int i = 0; i < l; i++)
    {
        if (s[i] - '0')
            ones++;
        else
            zeroes++;
    }
    cout << abs(ones - zeroes) << endl;
    return 0;
}

