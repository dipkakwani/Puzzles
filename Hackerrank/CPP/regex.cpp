#include <bits/stdc++.h>
#include <regex>
using namespace std;


int main() {
    vector<string> inp, ans;
    int n;
    string s;
    cin >> n;
    while (n--)
    {
        cin >> s;
        smatch m;
        regex e ("\\d{3}-\\d{2}-\\d{2}-\\d{8}-[A-Z]");
        while (regex_search (s,m,e)) {
            for (auto x:m)
            	ans.push_back(x);
            s = m.suffix().str();
        }
    }
    sort(ans.begin(), ans.end());
    set<string> res(ans.begin(), ans.end());
    bool empty = (res.size())?0:1; 
    for (auto i = res.begin(); i != res.end(); i++)
        cout << (*i) << endl;
    if (empty)
        cout << "JUNK\n";
    return 0;
}
