/*
Griet Coders gave ranking to the best programmers present in their campus but some people are not present for the prize distribution day and the people who are present are n in count are listed rankwise in the increasing order of their rank but unfortunately the list was printed wrongly and some of the people are printed mistakenly in different places so that one of the sublist is unsorted now the event manager wants to sort the list so that he would get the correct list,the time is very less and he should do it in minimum time so please help the event manager in identifying the unsorted sublist
Major problem:The Major problem is given array A[] of size n and the user should identify the starting and ending indices of the sublist which is unsorted in the given array
note:the indexing of the array should start at 1
Note:Assume that every array is unsorted somewhere
Input

Input description.
First line of input contains an integer T denoting number of test cases
First line of each test case contains an integer n denoting number of elements in array
next line contains n space separated integers of array
Output

Output description.
For the test case output i,j where i and j are the start index and ending index of unsorted sublist respectively
Constraints

1 ≤ T,n ≤ 105
1 ≤ array element ≤ 109
 
Example

Input:
2
6
1 2 4 3 5 6
7
10 12 11 14 13 15 16
Output:
3,4
2,5

Solution: 

Compare each element of the vector with the corresponding element of sorted version of the vector.
First and last element which is unequal in both the vectors gives i and j respectively.
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{

	int t, n;
	cin >> t;	
	while (t--)
	{
		long long temp;
		cin >> n;
		vector<long long> a, b;
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			a.push_back(temp);
		}
		b = a;
		sort(b.begin(), b.end());
		int idx1 = -1, idx2 = -1;
		for (int i = 0; i < n; i++)
		{
			if (idx1 == -1 && a[i] != b[i])
				idx1 = i;
			if (a[i] != b[i])
				idx2 = i;
		}
		cout << idx1 + 1 << "," << idx2 + 1 << endl;
	}
    	return 0;
}
