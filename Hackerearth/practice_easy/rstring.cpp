#include <iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int main()
{

    int t;
    scanf("%d", &t);
    while (t--)
    {
        char s[1000001];
        scanf("%s", s);
        int n = strlen(s), mx = -1, cnt = 0, pos_temp = 0, start_pos = 0, l = 0, length = 1;
        
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'K')
            {
                cnt++;
            }
            else
                cnt--;
            
            if (cnt < 0)
            {
                cnt = 0;
                l = 0;
                pos_temp = i + 1;
                continue;
            }
            l++;
            if (cnt >= mx)
            {
                mx = cnt;
                start_pos = pos_temp;
                length = l;
            }
            
            
        }
        cnt = 0;
        //printf("start %d length %d \n", start_pos, length);
        for (int i = 0; i < n; i++)
        {
            
            if (i >= start_pos && i <= start_pos + length - 1)
            {
                if (s[i] == 'K')
                    cnt++;
            }
            else if (s[i] == 'R')
                cnt++;
        
        }
        printf("%d\n", cnt);
    }
    return 0;
}
