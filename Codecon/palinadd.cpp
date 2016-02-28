//Problem        : Expecto Palindronum
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
    int len = s.length();
    int res = 0;
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[j] != s[len - 1 - i])
        {
        	res++;
        }
        else
        	j++;
    }
    cout << res + len << endl;
    return 0;
}
