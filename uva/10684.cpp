#include <bits/stdc++.h>
using namespace std;
typedef vector<long long> vl;
long long max_streak(vl& a)
{
	long long mx = 0, sm = 0;
	int size = a.size();
    for (int i = 0; i < size; i++)
    {
        sm += a[i];
        if (mx < sm)
            mx = sm;
        if (sm < 0)
            sm = 0;
    }
    if (mx > 0)
        return mx;
    return -1;
}
int main()
{
    int n;
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        vl a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        long long res = max_streak(a);
        if (res == -1)
            cout << "Losing streak.\n";
        else
            cout << "The maximum winning streak is " << res << ".\n";
    }
}
