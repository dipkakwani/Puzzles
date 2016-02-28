#include<bits/stdc++.h>
using namespace std;
 
bool place(vector<int>& a, vector<int>& res, vector<bool>& votes, int n, int i)
{
    if (res.size() == n || i == n)
        return 1;
    vector<int> options;
    if (!a[i])
        return place(a, res, votes, n, i + 1);
    for (int j = 0; j < n; j++)
    {
        if (!votes[j] && j != i)
            options.push_back(j);
    }
    for (auto it = options.begin(); it != options.end(); it++)
    {
        a[i]--;
        res.push_back(*it + 1);
        votes[*it] = 1;
 
        if (place(a, res, votes, n, i))
            return 1;
        res.pop_back();
        a[i]++;
        votes[*it] = 0;
    }
 
    return 0;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, s = 0;
        bool flag = false;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            s += x;
            a[i] = x;
            if (x == n)
                flag = true;
        }
        if (s > n || flag)
        {
            cout << "-1\n";
            continue;
        }
        vector<int> res;
        vector<bool> votes(n);
        if (place(a, res, votes, n, 0))
        {    
            for (auto i = res.begin(); i != res.end(); i++)
                cout << (*i) << " ";
            cout << endl;
        }
        else
            cout << "-1\n";
    }
    
    return 0;
}
