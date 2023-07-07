#include<bits/stdc++.h>
using namespace std;

vector<int> shortest(unordered_map<int,vector<int>> &mp, int n, int source)
{
    vector<int> dist(n);
    vector<int> mark(n);
    mark[source]=1;
    queue<int> q;
    q.push(source);
    while(!q.empty())
    {
        int u =q.front();
        q.pop();
        for(auto x: mp[u])
        {
            if(mark[x]!=1)
            {
                dist[x]=dist[u]+1;
                mark[x]=1;
                q.push(x);
            }
        }
    }
    return dist;
}