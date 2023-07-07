#include <bits/stdc++.h>
using namespace std;

bool isValid(int x, int y)
{
    return (x >= 0 && y >= 0 && x < 8 && y < 8);
}
int chessBoard(pair<int, int> initial, pair<int, int> target)
{
    vector<int> dx = {2, 1, 2, 1, -1, -2, -1, -2};
    vector<int> dy = {1, 2, -1, -2, 2, 1, -2, -1};
    queue<pair<int, pair<int, int>>> q;
    vector<int> mark(8 * 8);
    q.push(make_pair(0, initial));
    int u = 0;
    while (!q.empty())
    {
        pair<int, pair<int, int>> temp = q.front();
        q.pop();
        u = temp.first;
        pair<int, int> pos = temp.second;
        mark[pos.first * 8 + pos.second] = 1;
        if (target.first == pos.first && target.second == pos.second)
            return u;
        u++;
        for (int i = 0; i < 8; i++)
        {
            int x = pos.first + dx[i];
            int y = pos.second + dy[i];
            if ( isValid(x, y) && mark[x * 8 + y] != 1)
            {
                // cout << u << " " << x << " " << y << endl;
                q.push(make_pair(u, make_pair(x, y)));
            }
        }
    }
    return u;
}

int main()
{
    int a, b;
    cin >> a >> b;
    pair<int, int> initial = make_pair(a, b);
    cin >> a >> b;
    pair<int, int> target = make_pair(a, b);
    cout << chessBoard(initial, target) << endl;
}