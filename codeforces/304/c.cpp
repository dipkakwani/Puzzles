#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, t;
    cin >> n;
    deque<int> a, b;
    int n1, n2;
    cin >> n1;
    for (int i = 0; i < n1; i++)
    {
        cin >> t;
        a.push_front(t);
    }
    cin >> n2;
    for (int i = 0; i < n2; i++)
    {
        cin >> t;
        b.push_front(t);
    }
    int res = 0, count = 0;
    bool flag = true;
    while (!b.empty() && !a.empty())
    {
        if (a.back() > b.back())
        {
            int x = a.back();
            a.pop_back();
            a.push_front(b.back());
            b.pop_back();
            a.push_front(x);
        }
        else
        {
            int x = b.back();
            b.pop_back();
            b.push_front(a.back());
            a.pop_back();
            b.push_front(x);
        }
        count++;
        res++;
        if (count == 2000)
        {
            flag = false;
            cout << -1 << endl;
            break;
        }
    }
    if (flag)
    {
        cout << res << " ";
        if (b.empty())
            cout << "1\n";
        else if (a.empty())
            cout << "2\n";
    }
    return 0;
}
