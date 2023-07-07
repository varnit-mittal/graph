#include<bits/stdc++.h>
using namespace std;

void addNode(unordered_map<int,vector<int>> &mp, int a, int b)
{
    mp[a].push_back(b);
    mp[b].push_back(a);
}

void dfs_util(unordered_map<int,vector<int>> &mp, unordered_map<int,vector<int>> &group, int i, int x,vector<int> &mark)
{
    mark[i]=1;
    group[x].push_back(i);
    for(auto j:mp[i])
    {
        if(mark[j]!=1)
        {
            dfs_util(mp,group,j,x,mark);
        }
    }
}

int a=0;
unordered_map<int,vector<int>> dfs(unordered_map<int,vector<int>> &mp, int n)
{
    unordered_map<int,vector<int>> group;
    vector<int> mark(n);
    for(int i=0;i<n;i++)
    {
        if(mark[i]!=1)
        {
            dfs_util(mp,group,i,a,mark);
            a++;
        }
    }
    return group;
}

int noGroup(unordered_map<int,vector<int>> &group)
{
    int s=0;
    for(int i=0;i<a;i++)
    {
        int k=group[i].size();
        s+= ((k)*(k-1))/2;
    }
    return s;
}

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    unordered_map<int,vector<int>> mp;
    for(int i=0;i<k;i++)
    {
        int e,f;
        cin >> e >>f;
        addNode(mp,e,f);
    }
    int d= ((n)*(n-1))/2;
    
}