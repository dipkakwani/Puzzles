#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t, j;
	int i, len, min_not_zero, idx;
	cin >> t;
	for (j = 0; j < t; j++)
	{
		string s, s1;
		pair<int, int> max_in_right[20];
		pair<int, int> min_in_right[20];
		cin >> s;
		len = s.length();

		max_in_right[len - 1] = make_pair(s[len - 1] - '0', len - 1);
		min_in_right[len - 1] = make_pair(s[len - 1] - '0', len - 1);
		for (i = len - 2; i >= 0; i--)
		{
			if ((s[i] - '0') > max_in_right[i + 1].first)
				max_in_right[i] = make_pair((s[i] - '0'), i);
			else
				max_in_right[i] = max_in_right[i + 1];
			if ((s[i] - '0') < min_in_right[i + 1].first)
				min_in_right[i] = make_pair((s[i] - '0'), i);
			else
				min_in_right[i] = min_in_right[i + 1];
		}

		min_not_zero = (s[0] - '0');
		idx = 0;
		for (i = 1; i < len; i++)
		{
			if ((s[i] - '0') <= min_not_zero && (s[i] - '0') != 0)
			{
				min_not_zero = (s[i] - '0');
				idx = i;
			}
		}
		min_in_right[0] = make_pair(min_not_zero, idx);

		s1 = s;
		for (i = 0; i < len; i++)
		{
			if ((s[i] - '0') < max_in_right[i].first)
			{
				swap(s[i], s[max_in_right[i].second]);
				break;
			}
		}
		for (i = 0; i < len; i++)
		{
			if ((s1[i] - '0') > min_in_right[i].first)
			{
				swap(s1[i], s1[min_in_right[i].second]);
				break;
			}
		}

		cout << "Case #" << j + 1 << ": " << s1 << " " << s << endl;
	}
}
