#include<bits/stdc++.h>
#include<math.h>
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

int dist(int x1, int x2, int y1, int y2)
{
int disx= abs(x1-x2);
int disy= abs(y1-y2);
return disx+disy;
}

int main()
{
int n;
cin >> n;
vector<pair<int,int>> v;
for(int i=0;i<n;i++)
{
int x,y;
cin >> x >> y;
v.push_back(make_pair(x,y));
}
vector<pair<int,pair<int,int>>> edge;
for(int i=0;i<n;i++)
{
int x1=v[i].first;
int y1=v[i].second;
for(int j=i+1;j<n;j++)
{
int x2=v[j].first;
int y2=v[j].second;
int w= dist(x1,x2,y1,y2);
addEdge(edge,i,j,w);
}
}

sort(edge.begin(),edge.end());
cout << kruskal(edge,n)<< endl;
}