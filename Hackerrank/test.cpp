#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    string a, b;
    int count1[26] = {0}, count2[26] = {0}, res = 0;
    cin >> a >> b;
    for (int i = 0; i < a.length(); i++)
        count1[a[i] - 'a'] += 1;
    for (int i = 0; i < b.length(); i++)
        count2[b[i] - 'a'] += 1;
    for (int i = 0; i < 26; i++)
        res += (int)abs(count1[i] - count2[i]);
    cout << res << endl;
    return 0;
}

