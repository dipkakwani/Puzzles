#include<bits/stdc++.h>
using namespace std;
int main () {
    int n, x;
    cin >> n;
    vector<int> count(1001);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        count[x]++;
    }
    for (int i = 0; i < 1001; i++)
    {
        if (count[i] == 1)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
