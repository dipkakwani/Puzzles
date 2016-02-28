#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, k ,w;
    cin >> k >> n >> w;
    unsigned long long ans = (k * w * (w + 1) / 2);
    if (ans > n)
        ans = ans - n;
    else
        ans = 0;
    cout << ans << endl;
    return 0;
}
