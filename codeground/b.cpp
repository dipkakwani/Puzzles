#include <bits/stdc++.h>
using namespace std;
int r, c;

vector< vector<int> > matrix(501, vector<int>(501));

void right(pair<int, int>& cur_cell)
{
    cur_cell.second++;
    cout << matrix[cur_cell.first][cur_cell.second] << " ";
    //cout << cur_cell.first << " " << cur_cell.second << "\n";

}

void down(pair<int, int>& cur_cell)
{
    cur_cell.first++;
    cout << matrix[cur_cell.first][cur_cell.second] << " ";
    //cout << cur_cell.first << " " << cur_cell.second << "\n";

}

void left_diag(pair<int, int>& cur_cell)
{
    while (cur_cell.second > 0 && cur_cell.first < r - 1 && cur_cell != pair<int, int>(r - 1, c - 1))
    {
        //cout << "LD \n";
        cur_cell.first++;
        cur_cell.second--;
        cout << matrix[cur_cell.first][cur_cell.second] << " ";
        //cout << cur_cell.first << " " << cur_cell.second << "\n";
    }

}

void right_diag(pair<int, int>& cur_cell)
{
    while (cur_cell.second < c - 1  && cur_cell.first > 0 && cur_cell != pair<int, int>(r - 1, c - 1))
    {
        //cout << "RD \n";
        cur_cell.first--;
        cur_cell.second++;
        cout << matrix[cur_cell.first][cur_cell.second] << " ";
        //cout  << cur_cell.first << " " << cur_cell.second << "\n";
    }

}
int main()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> matrix[i][j];

    pair<int, int> cur_cell = pair<int, int>(0, 0);
    cout << matrix[cur_cell.first][cur_cell.second] << " ";

    while (cur_cell != pair<int, int>(r - 1, c - 1))
    {
        if (cur_cell.second < c - 1)
            right(cur_cell);
        else
            down(cur_cell);
        if (cur_cell == pair<int, int>(r - 1, c - 1))
            break;

        // Left diagonal
        left_diag(cur_cell);
        if (cur_cell == pair<int, int>(r - 1, c - 1))
            break;

        if (cur_cell.first < r - 1)
            down(cur_cell);
        else
            right(cur_cell);

        if (cur_cell == pair<int, int>(r - 1, c - 1))
            break;

        // Right diagonal
        right_diag(cur_cell);
        if (cur_cell == pair<int, int>(r - 1, c - 1))
            break;
    }
    cout << endl;
    return 0;
}
