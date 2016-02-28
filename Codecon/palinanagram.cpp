//Problem        : A Compliance Problem
//Language       : C++
//Compiled Using : g++
//Version        : GCC 4.9.1
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

#include <iostream>
#include <string>
#include <algorithm>
#include <climits> 
using namespace std;
int main() {
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    bool odd = false, flag = true;
    int count = 1;
    for (int i = 0; i < s.length() - 1; i++)
    {
    	if (s[i] == s[i + 1])
    		count++;
    	else
    	{
    		if (count % 2)        
            {
                if (odd)
                {
                    cout << "no\n";
                    flag = false;
                    break;
                }
                else
                    odd = true;
            }
            count = 1;
    	}
    }
    if (flag && (count % 2) && odd)
    	cout << "no\n";
    else if (flag)
        cout << "yes\n";
    return 0;
}
