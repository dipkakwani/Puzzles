#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string color;
        cin >> color;
        string final_color(n, 'A');
        pair<int, int> x(0, k - 1);

        for (int i = 0; i < k; i++)
            final_color[i] = color[0];
        
        int res = 0;
        while (x.second < n)
        {
            int remove = 0;
            int max_remove = (x.second + k == n)? n - k: k;
            for (int i = x.first; i < n && remove < max_remove && color[x.first] == color[i]; i++, remove++)
                final_color[i] = color[x.first];

            x.first = x.first + remove;
            x.second = x.second + remove;
            res++;
            if (remove == 0)   
                break;
        }        
        if (final_color != color)
            cout << "-1\n";
        else
            cout << res << endl;
    }

    return 0;
}
