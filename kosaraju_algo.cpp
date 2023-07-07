#include <bits/stdc++.h>
using namespace std;

void addNode(unordered_map<int, vector<int>> &mp, int i, int value)
{
    mp[i].push_back(value);
}

unordered_map<int, vector<int>> transpose(unordered_map<int, vector<int>> &mp, int n)
{
    unordered_map<int, vector<int>> trans;
    for (int i = 0; i < n; i++)
    {
        for (auto x : mp[i])
        {
            addNode(trans, x, i);
        }
    }
    return trans;
}

void finishTime_util(unordered_map<int, vector<int>> &mp, vector<int> &mark, vector<int> &time, int i)
{
    mark[i] = 1;
    for (auto x : mp[i])
    {
        if (mark[x] != 1)
            finishTime_util(mp, mark, time, x);
    }
    time.push_back(i);
}

void dfs(unordered_map<int, vector<int>> &mp, vector<int> &mark, int i)
{
    mark[i] = 1;
    cout << i << " ";
    for (auto x : mp[i])
    {
        if (mark[x] != 1)
            dfs(mp, mark, x);
    }
}

vector<int> finishTime(unordered_map<int, vector<int>> &mp, int n)
{
    vector<int> time;
    vector<int> mark(n);
    for (int i = 0; i < n; i++)
    {
        if (mark[i] != 1)
            finishTime_util(mp, mark, time, i);
    }
    reverse(time.begin(),time.end());
    return time;
}
void print(unordered_map<int, vector<int>> &mp, int n, vector<int> &time)
{
    vector<int> mark(n);
    for (int i = 0; i < n; i++)
    {
        if (mark[time[i]] != 1)
        {
            dfs(mp, mark, time[i]);
            cout << endl;
        }
    }
}

int main()
{
    int n=5;
    unordered_map<int,vector<int>> graph;
    while(1)
    {
        int i;
        cin >> i;
        if(i==-1)
        break;
        int val;
        cin >> val;
        addNode(graph,i,val);
    }
    vector<int> time=finishTime(graph,n);
    unordered_map<int,vector<int>> trans=transpose(graph,n);
    print(trans,n,time);
}