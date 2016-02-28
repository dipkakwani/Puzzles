#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, k, idx = 0;
    cin >> n >> k;
    vector<int> snipers (k);
    for (int i = 0; i < k; i++)
        cin >> snipers[i];
    int res = k;
    sort (snipers.begin (), snipers.end ());
    for (int i = 1; i <= n; i++)
    {
        if (idx < k && (i == snipers[idx] - 1 || i == snipers[idx]))
            continue;
        else if (idx < k && i == snipers[idx] + 1)
            idx++;
        else
            i++, res++;
    }
    cout << res << endl;
    return 0;
}
