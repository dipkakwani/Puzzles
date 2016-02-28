#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <bits/stdc++.h>
#define MAX 100000
using namespace std;
typedef long long ll;
char memo[1000000001];

ll gcd(ll a, ll b)
{
    return (b == 0)?a:gcd(b, a % b);
}

ll GCD(ll a[MAX], int start, int end)
{
    ll res = 0;
    for (int i = start; i != end; i++)
        res = gcd(res, a[i]);
    return res;
}

bool subset_gcd(ll a[MAX], ll k, int start, ll res, int size)
{
    if (memo[res] != '0')
        return (memo[res] == '1')?0:1;
    if (res == k)
    {
        memo[k] = '2';
        return 1;
    }
    if (start >= size)
    {
        memo[res] = '1';
        return 0;
    }
    ll g = gcd(res, a[start]);
    memo[res] = (subset_gcd(a, k, start + 1, res, size) == 1)?'2':'1';
    memo[g] = (subset_gcd(a, k, start + 1, g, size) == 1)?'2':'1';
    return (memo[res] - '1') || (memo[g] - '1');
}
int main() {
    ll a[MAX];
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        ll k;
        cin >> n >> k;

        for (int i = 0; i < n; i++)
            cin >> a[i];
        memset(memo, '0', *max_element(a, a + n) + 1);
        if (subset_gcd(a, k, 0, 0, n))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}

