#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int,pair<int,int>>> &v, int x, int y, int w)
{
    v.push_back({w,{x,y}});
}

typedef struct Edge{
    vector<int> parent;
    vector<int> rank;

    Edge(int n)
    {
        for(int i=0;i<n;i++)
        {
            parent.push_back(-1);
            rank.push_back(0);
        }
    }

    int find(int i)
    {
        if(parent[i]==-1)
        return i;
        return parent[i]= find(parent[i]);
    }

    void unite(int x, int y)
    {
        x=find(x);
        y=find(y);
        if(x!=y)
        {
            if(rank[x]<rank[y])
            parent[x]=y;
            else if(rank[x]>rank[y])
            parent[y]=x;
            else
            {
                parent[y]=x;
                rank[x]+=1;
            }
        }
    }
} Edge;

int kruskal(vector<pair<int,pair<int,int>>> &v, int n)
{
    int res=0;
    Edge *e= new Edge(n);
    for(int i=0,s=0;s<n-1;i++)
    {
        if(e->find(v[i].second.first)!=e->find(v[i].second.second))
        {
            e->unite(v[i].second.first,v[i].second.second);
            res+=v[i].first;
            s++;
        }
    }
    return res;
}

int main()
{
    vector<pair<int,pair<int,int>>> v;
    set<int> s;
    while(1)
    {
        int x;
        cin >> x;
        if(x==-1)
        break;
        int y, w;
        cin >> y>> w;
        addEdge(v,x,y,w);
        s.insert(x);
        s.insert(y);
    }
    int n=0;
    for(auto i:s)
    {
        n=i+1;
    }
    // cout << n << endl;
    sort(v.begin(),v.end());
    // for(int i=0;i<n;i++)
    // {
    //     cout << v[i].first << " "<< v[i].second.first << " "<< v[i].second.second << endl;
    // }
    cout << kruskal(v,n)<< endl;
}