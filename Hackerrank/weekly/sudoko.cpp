#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
bool square_check(vector<vector<int>>& board, int i, int j)
{
    vector<bool> present(9);
    for (int x = i; x < i + 3; x++)
        for (int y = j; y < j + 3; y++)
            present[board[x][y] - 1] = 1;
    for (int x = 0; x < 9; x++)
        if (!present[x])
            return false;
    return true;
}
bool check(vector<vector<int>>& board)
{
    bool flag = false;
    for (int i = 0; i < 9; i++)
    {
        vector<bool> row_present(9), col_present(9);
        for (int j = 0; j < 9; j++)
        {
            row_present[board[i][j] - 1] = 1;
            col_present[board[j][i] - 1] = 1;
        }

        for (int j = 0; j < 9; j++)
        {
            if (!row_present[j] || !col_present[j])
            {
               // cout << i << "  "<< j << endl;
                return false;

            }
        }
    }    

    for (int i = 0; i < 9; i+=3)
        for (int j = 0; j < 9; j+=3)
            if (!square_check(board, i, j))
                return false;
    return true;
}

set<pair<ii, ii>> solve(vector<vector<int>>& board)
{
    set<pair<ii, ii>> res;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            for (int k = 0; k < 9; k++)
            {
                for (int l = 0; l < 9; l++)
                {
                    if ((i != k || j != l) && board[i][j] != board[k][l])
                    {
                        swap(board[i][j], board[k][l]);
                        /*
                        for (int x = 0; x < 9; x++)
                        {
                            for (int y = 0; y < 9; y++)
                                cout << board[x][y] << " ";
                            cout << endl;
                        }
                        
                        cout << endl;
                        */
                        if (check(board))
                        {
                            if (res.find(pair<ii, ii>(ii(k + 1, l + 1), ii(i + 1 , j + 1))) == res.end())
                                res.insert(pair<ii, ii>(ii(i + 1, j + 1), ii(k + 1 , l + 1)));
                        }
                        swap(board[i][j], board[k][l]);                       
                    }
                }
            }
        }
    }
    return res;
}     
int main()
{
    vector<vector<int>> board(9, vector<int>(9));
    int t, x;
    cin >> t;
    for (int T = 1; T <= t; T++)
    {
        bool flag = true;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cin >> x;
                board[i][j] = x;
            }
        }
        
        set<pair<ii, ii>> result = solve(board);
               
        vector<pair<ii, ii>> res(result.begin(), result.end());
        sort(res.begin(), res.end());
        cout << "Case #" << T << ":\n";
        for (auto i = res.begin(); i != res.end(); i++)
        {
            flag = false;
            cout << "(" << (*i).first.first << "," << (*i).first.second << ") <-> (" << (*i).second.first << "," << (*i).second.second << ")\n";
        }
        if (flag)
            cout << "Serendipity\n";
       
    }
    return 0;
}
