#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

bool isValid(vector<vector<int>> &v, int row, int col)
{
    return (row >= 0 && col >= 0 && row < v.size() && col < v[0].size());
}

vector<pair<int, int>> neighbours(vector<vector<int>> &v, int row, int col, int start)
{
    vector<pair<int, int>> ans;
    vector<pair<int, int>> index = {{row + 1, col}, {row - 1, col}, {row, col + 1}, {row, col - 1}};
    for (int i = 0; i < index.size(); i++)
    {
        pair<int, int> p;
        p.first = index[i].first;
        p.second = index[i].second;
        if (isValid(v, p.first, p.second))
        {
            if (v[p.first][p.second] == start)
                ans.push_back(p);
        }
    }
    return ans;
}

void floodFill(vector<vector<int>> &v, int row, int col, int p)
{
    int start = v[row][col];
    queue<pair<int, int>> q;
    q.push({row, col});
    unordered_map<int, int> mark;
    while (!q.empty())
    {
        row = q.front().first;
        col = q.front().second;
        q.pop();
        mark[row] = col;
        v[row][col] = p;
        // cout << row << " " << col << endl;
        vector<pair<int, int>> sol = neighbours(v, row, col, start);
        for (int i = 0; i < sol.size(); i++)
        {
            // cout << sol[i].first << " " << sol[i].second<<endl;
            if (mark.find(sol[i].first) != mark.end())
            {
                if (mark[sol[i].first] != sol[i].second)
                {
                    q.push(sol[i]);
                }
            }
            else
            {
                q.push(sol[i]);
            }
        }
    }
}

int main()
{
    int m, n;
    vector<vector<int>> v;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        vector<int> w;
        for (int j = 0; j < n; j++)
        {
            int d;
            cin >> d;
            w.push_back(d);
        }
        v.push_back(w);
    }

    int r, c, color;
    cin >> r >> c >> color;
    if (color != v[r][c])
        floodFill(v, r, c, color);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}