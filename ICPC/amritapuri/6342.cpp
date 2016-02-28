#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        set<string> s;
        int n = a.length();
        for (int i = 0; i < n; i++)
            for (int j = 1; j <= n - i; j++)
                s.insert(a.substr(i, j));
        
        set<string> rev_s;

        for (auto i = s.begin(); i != s.end(); i++)
        {
            string x = *i;
            reverse(x.begin(), x.end());
            rev_s.insert(x);
        }

        if (s == rev_s)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
