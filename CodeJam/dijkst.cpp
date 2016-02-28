#include <bits/stdc++.h>
using namespace std;
int ijk[8][8] = {
        {1, 0, 3, 2, 5, 4, 7, 6},
        {0, 1, 2, 3, 4, 5, 6, 7},
        {3, 2, 0, 1, 6, 7, 5, 4},
        {2, 3, 1, 0, 7, 6, 4, 5},
        {5, 4, 7, 6, 0, 1, 2, 3},
        {4, 5, 6, 7, 1, 0, 3, 2},
        {7, 6, 4, 5, 3, 2, 0, 1},
        {6, 7, 5, 4, 2, 3, 1, 0}
};
int dp[10000][10009];
bool check(long long l, long long x)
{
    vector<int> l1, l2;
    for (int i = 0; i < l + 9; i++)
        if (dp[0][i] == 2)
            l1.push_back(i);
    for (int i = 0; i < l + 9; i++)
        if (dp[0][i] == 6)
            l2.push_back(i + 1);
    for (vector<int>::iterator i = l1.begin(); i != l1.end(); i++)
    {
        //cout << *i << endl;
        for (vector<int>::iterator j = l2.begin(); j != l2.end(); j++)
        {
            //cout << *j << endl;
            if (*i + 1 > *j)
                *j += l;
            //{
                if (dp[(*i + 1) % l][(*j - 1) % l] == 4)
                    return 1;
            //}
        }    
    }
    return 0;
}
int main()
{
    int t;
    cin >> t;
    for (int X = 1; X<= t; X++)
    {
        long long l, x;
        string a;
        cin >> l >> x;
        cin >> a;
        for (int i = 0; i < l; i++)
        {
            if (a[i] == 'i')
                a[i] = '2';
            else if (a[i] == 'j')
                a[i] = '4';
            else
                a[i] = '6';
        }
        for (int i = 0; i < l; i++)
        {
            for (int j = i; j < l + 9; j++)
            {
                if (j > i)
                    dp[i][j] = ijk[dp[i][j - 1]][(a[j % l] - '0')];
                else
                    dp[i][j] = (a[j] - '0');
            }
        }
        
        cout << a << endl;
        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < l + 9; j++)
                cout << dp[i][j] << "  ";
            cout << endl;
        }
        
        cout << "Case #" << X << ": ";
        if (check(l, x))
            cout << "YES\n";
        else
            cout <<"NO\n";

    }
    return 0;
}
