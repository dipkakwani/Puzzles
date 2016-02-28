#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while (1)
    {
        getline(cin, s);
        if (s == "DONE")
            break;
        string chars;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != '.' && s[i] != ',' && s[i] != '!' && s[i] != '?' && s[i] != ' ')
                chars += tolower(s[i]);
        }
        bool palin = true;
        int len = chars.length();
        for (int i = 0; i < len / 2; i++)
        {
            if (chars[i] != chars[len - 1 - i])
            {
                palin = false;
                break;
            }
        }
        if (palin)
            cout << "You won't be eaten!\n";
        else
            cout << "Uh oh..\n";
    }
    return 0;
}
