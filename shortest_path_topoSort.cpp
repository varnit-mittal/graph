#include<bits/stdc++.h>
using namespace std;

void addNode(unordered_map<int,vector<pair<int,int>>> &mp, int i, int value, int wieght)
{
    pair<int,int> p;
    p.first=value;
    p.second=wieght;
    mp[i].push_back(p);
}

void countIndegree(unordered_map<int,vector<pair<int,int>>> &mp, vector<int> &indegree, int i,vector<int> &mark)
{
    mark[i]=1;
    for(auto x: mp[i])
    {
        // cout <<i<<" "<< x << " ";
        indegree[x.first]+=1;
        // cout <<indegree[x]<<endl;
        if(mark[x.first]!=1)
        countIndegree(mp,indegree,x.first,mark);
    }
}

vector<int> countComp(unordered_map<int,vector<pair<int, int>>> &mp, int n)
{
    vector<int> indegree(n);
    vector<int> mark(n);
    for(int i=0;i<n;i++)
    {
        if(mark[i]!=1)
        countIndegree(mp,indegree,i,mark);
    }
    return indegree;
}

vector<int> topoSort(vector<int> &indegree, unordered_map<int,vector<pair<int, int>>> &mp)
{
    queue<int> q;
    vector<int> topo;
    for(int i=0;i<indegree.size();i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int u= q.front();
        topo.push_back(u);
        q.pop();
        for(auto x: mp[u])
        {
            indegree[x.first]--;
            if(indegree[x.first]==0)
            q.push(x.first);
        }
    }
    return topo;
}

vector<int> shortestPath(unordered_map<int,vector< pair<int, int>>> &mp, int n, int source)
{
    vector<int> dist(n,INT_MAX);
    dist[source]=0;
    vector<int> indeg=countComp(mp,n);
    vector<int> topo=topoSort(indeg,mp);
    for(auto x: topo)
    {
        for(auto y: mp[x])
        {
            if(dist[y.first]%100007>dist[x]%100007+y.second%100007)
            {
                dist[y.first]=dist[x]+y.second;
            }
        }
    }
    return dist;
}

int main()
{
    unordered_map<int,vector<pair<int,int>>> mp;
    int n=6;
    while(1)
    {
        int i;
        cin >> i;
        if(i==-1)
        break;
        int val, wieght;
        cin >> val;
        // cout << "wieght ";
        cin >> wieght;
        addNode(mp,i,val,wieght);
    }

    vector<int> dist=shortestPath(mp,n,0);
    for(int i=0;i<n;i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
}