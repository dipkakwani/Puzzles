#include <bits/stdc++.c>
using namspace std;
int n;
vector< vector<int> > matrix(20, vector<int>(101));
void build_matrix(int x)
{
    int k = 0;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < (2 * i + 1); j++)
            matrix[i][j] = k++;
    }
}

vector< vector< pair<int, int> > graph(101);
void build_graph()
{
    bool odd = false;
    for (int i = 0; i < n / 2; i++)
    {
        odd = i & 1;
        for (int j = 0; j < (2 * i + 1); j++)
        {
            if (j + 1 < (2 * i + 1))
                graph[matrix[i][j]] = pair<int, int>(matrix[i][j + 1], 0);
            if (odd)
                graph[matrix[i][j]] = pair<int, int>(matrix[i + 1][j + 1], 0);


        }
    }
}
int main()
{
    cin >> n;  
    build_matrix(n);
    build_graph();
    return 0;
}
