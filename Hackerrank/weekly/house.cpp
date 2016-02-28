#include <bits/stdc++.h>
using namespace std;
int solve(vector<pair<int, int>>& intervals)
{
    int n = intervals.size();
    vector<pair<int, bool>> event(2 * n);
    for (int i = 0; i < n; i++)
    {
        event[2 * i].first = intervals[i].first;
        event[2 * i].second = 0;
        event[2 * i + 1].first = intervals[i].second;
        event[2 * i + 1].second = 1;
    }
    sort(event.begin(), event.end());
    vector<int> ans(n);
    int counter = 0, idx = 0, res = -1;
    for (int i = 0; i < n; i++)
    {
    	while (idx < 2 * n && event[idx].first == i && !event[idx].second)
    		counter++, idx++;

    	ans[i] = counter;

    	while (idx < 2 * n && event[idx].first == i && event[idx].second)
    		counter--, idx++;
    }
    for (int i = 0; i < n; i++)
    	if (ans[i] > i)
    		res = i;

    return res + 1;
}
int main()
{
    int n, x, y;
    cin >> n;
    vector<pair<int, int>> intervals(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        intervals[i] = pair<int, int>(x, y);
    }
    cout << solve(intervals) << endl;
}
