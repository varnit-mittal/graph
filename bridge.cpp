#include <bits/stdc++.h>
using namespace std;

void addNode(unordered_map<int, vector<int>> &mp, int i, int val)
{
    mp[i].push_back(val);
    mp[val].push_back(i);
}

void dfs(unordered_map<int, vector<int>> &mp, int j, int i, vector<int> &mark, int a, int parent)
{
    mark[i] = 1;
    for (auto x : mp[i])
    {
        if (mark[x] != 1 && (x != j || i != a))
        {
            dfs(mp, j, x, mark, a, i);
        }
    }
}

vector<pair<int, int>> isBridge(unordered_map<int, vector<int>> &mp, int n)
{
    vector<pair<int, int>> bridge;
    for (int i = 0; i < n; i++)
    {
        for (auto x : mp[i])
        {
            vector<int> mark(n);
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (mark[j] != 1)
                {
                    dfs(mp, x, j, mark, i, i);
                    count++;
                }
            }
            if (count > 1)
                bridge.push_back(make_pair(i, x));
        }
    }
    return bridge;
}

int main()
{
    int n;
    priority_queue<int> pq;
    unordered_map<int, vector<int>> mp;
    while (1)
    {
        int i;
        cin >> i;
        if (i == -1)
            break;
        int j;
        cin >> j;
        addNode(mp, i, j);
        pq.push(i);
        pq.push(j);
    }
    n = pq.top() + 1;
    vector<pair<int, int>> ap = isBridge(mp, n);
    for (auto x : ap)
    {
        cout << x.first << " " << x.second << endl;
    }
}