#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int longestRun = 1, run = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1] - 1)
            run++;
        else
            run = 1;
        if (run > longestRun)
            longestRun = run;
    }
    cout << longestRun << endl;
    return 0;
}
