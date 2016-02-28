#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
    int n, b, h, w;
    while(cin >> n >> b >> h >> w)
    {
        int cost, rooms, res = 99999999;
        for (int i = 0; i < h; i++)
        {
            cin >> cost;
            for (int j = 0; j < w; j++)
            {
                cin >> rooms;
                if (rooms >= n && (cost * n) <= b)
                {
                    res = min(res, cost * n);
                }
            }
        }
        if (res > b)
            cout << "stay home\n";
        else
            cout << res << endl;
    }
    return 0;
}
