#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001
long long precompute[MAX];
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int mx = *max_element(a.begin(), a.end());
    for (int k = 1; k <= mx; k++)
    {
        long long res = 0;
        int run = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] % k == 0)
                run++;
            else
            {
                res += run *(run + 1) / 2;
                run = 0;
            }
        }
        res += run * (run + 1) / 2;
        precompute[k] = res;
    }
    int q;
    cin >> q;
    while (q--)
    {
        int k;
        cin >> k;
        cout << precompute[k] << endl;
    }
    return 0;
}

