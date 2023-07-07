#include<bits/stdc++.h>
using namespace std;

void addNode(unordered_map<int,vector<int>> &mp, int i, int value)
{
    mp[i].push_back(value);
    mp[value].push_back(i);
}
void addNode2(unordered_map<int,vector<int>> &mp, int i, int value, int x)
{
    if(i==x)
    {
        mp[i].push_back(value);
    }
    else if(value==x)
    {
        mp[value].push_back(i);
    }
    else
    {
        mp[i].push_back(value);
        mp[value].push_back(i);
    }
}

bool dfs(unordered_map<int,vector<int>> &mp, int i,vector<int> &mark)
{
    mark[i]=1;
    stack<int> s;
    s.push(i);
    while(!s.empty())
    {
        int u=s.top();
        s.pop();
        mark[u]=1;
        if(u==0)
        return true;
        for(auto x: mp[u])
        {
            // cout <<u<< " "<< x<<" ";
            if(mark[x]!=1)
            s.push(x);
        }
        // cout << endl;
    }
    return false;
}

int shortestPath(unordered_map<int,vector<int>> &mp, int n, int source, int l)
{
    vector<int> dist(n);
    vector<int> mark(n);
    queue<int> q;
    q.push(source);
    mark[source]=1;
    while(!q.empty())
    {
        int u=q.front();
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
    return dist[l];
}

vector<int> shortestPath2(unordered_map<int,vector<int>> &mp, int n, int source, int l)
{
    vector<int> dist(n);
    vector<int> mark(n);
    queue<int> q;
    q.push(source);
    mark[source]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto x: mp[u])
        {
            vector<int> mk(n);
            if(dfs(mp,x,mk)==false)
            {
                if(mark[x]!=1)
                {
                    dist[x]=dist[u]+1;
                    mark[x]=1;
                    q.push(x);
                }
            }
        }
    }
    return dist;
}

int main()
{
    int n,x;
    cin >>n >>x;
    x--;
    // cout << x<< endl;
    unordered_map<int,vector<int>> mp;
    unordered_map<int,vector<int>> graph;
    vector<int> indegree(n);
    for(int i=0;i<n-1;i++)
    {
        int j,val;
        cin >> j >> val;
        j--;
        val--;
        addNode(mp,j,val);
        addNode2(graph,j,val,x);
    }
    int dist1=shortestPath(mp,n,0,x);
    vector<int> dist2=shortestPath2(graph,n,x,x);
    sort(dist2.begin(),dist2.end());
    int dis2=dist2[n-1];
    // cout << dis2<<endl;
    cout << 2*(dist1+dis2)<< endl;
}