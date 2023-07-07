#include <bits/stdc++.h>
using namespace std;

bool disconnect(vector<vector<int>> &v, int m, int n)
{
    vector<int> dig(m + n - 1);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] == 1)
            {
                dig[i + j]++;
            }
        }
    }
    for (int i = 1; i < dig.size() - 1; i++)
    {
        // cout << i << " " << dig[i] << endl;
        if (dig[i] <= 1)
            return true;
    }
    return false;
}
int main()
{
    int m;
    int n;
    cin >> m >> n;
    vector<vector<int>> v;
    for (int i = 0; i < m; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            int d;
            cin >> d;
            temp.push_back(d);
        }
        v.push_back(temp);
    }

    if (disconnect(v, m, n))
        cout << 1 << endl;
    else
        cout << 0 << endl;
}