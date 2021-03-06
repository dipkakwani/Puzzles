/*
Griet Coders has new challenge on factorials,There are N number of coders in Griet,every Grietian has a unique number on his tshirt X.They decided to fom clubs of coders in a way that their club number is number of digits in the factorial of his tshirt number.Director of Griet is busy in another works so he needed your help to form the clubs of coders.
Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows."
The first line of each test case contains a single integer N denoting the number of Grietians
The second line contains N space-separated integers denoting tshirt numbers of Griet Coders
 
Output

Tips:
For each test case, output a single line containing N space separated numbers each denoting the Coders club number respectively

Constraints

1 ≤ T,N ≤ 10^5
1 ≤ X ≤ 25000
Example

Input:
2
3
4 6 8
4
1 5 10 12
Output:
2 3 5
1 3 7 9
*/
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main()
{
 
	int t, n, temp, count;
	double logarithm[25001];
	cin >> t;	
	logarithm[0] = logarithm[1] = 0;
	for (int i = 2; i < 25001; i++)
		logarithm[i] = logarithm[i - 1] + log10(i);
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			cout << floor(logarithm[temp] + 1) << " ";
		}
		cout << endl;
	}
    	return 0;
}
