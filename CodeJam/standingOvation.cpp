#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int X = 1; X<= t; X++)
    {
        int n;
        cin >> n;
        string shy;
        cin >> shy;
        int peopleStanding = (shy[0] - '0');
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i > peopleStanding && shy[i])
            {
                res += (i - peopleStanding);
                peopleStanding += ((shy[i] - '0') + i - peopleStanding);
            }
            else
                peopleStanding += (shy[i] - '0');
                
        }
        cout << "Case #" << X << ": " << res << endl;
    }
}
