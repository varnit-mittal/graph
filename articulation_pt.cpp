#include <bits/stdc++.h>
#include<unordered_set>
using namespace std;

void addNode(unordered_map<int, vector<int>> &mp, int i, int value)
{
    mp[i].push_back(value);
    mp[value].push_back(i);
}

void dfs(unordered_map<int, vector<int>> &mp, int j, int i, vector<int> &mark)
{
    if (i == j)
        return;
    mark[i] = 1;
    for (auto x : mp[i])
    {
        if (mark[x] != 1 && x != j)
            dfs(mp, j, x, mark);
    }
}

vector<int> articulate(unordered_map<int, vector<int>> &mp, int n)
{
    vector<int> ap;
    for (int i = 0; i < n; i++)
    {
        vector<int> mark(n);
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (mark[j] != 1 && j != i)
            {
                dfs(mp, i, j, mark);
                count++;
            }
        }
        if (count > 1)
            ap.push_back(i);
    }
    return ap;
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
    // for(auto x= s.begin();x!=s.end();x++)
    // {
    //     n=*x+1;
    // }
    n=pq.top()+1;
    // cout << n << endl;
    vector<int> ap = articulate(mp, n);
    for (auto x : ap)
    {
        cout << x << " ";
    }
    cout << endl;
}