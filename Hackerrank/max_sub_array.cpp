#include <cmath>
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
int main() 
{
    int t;
    cin >> t;
    while (t--)
    {
        ull k, n, mx, ans = 0, count = 0;
        cin >> n >> k;
        vector<ull> a(n);
        for (ull i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] <= k)
                count++;
            else
            {
	            ans += count * (count + 1) / 2;
            	count = 0;
            }
        }
        ans += count * (count + 1) / 2;
        ans = (n * (n + 1) / 2 - ans);
        cout << ans << endl;
    }
    return 0;
}
