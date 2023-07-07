#include<bits/stdc++.h>
using namespace std;

bool DFSRec(unordered_map<int,vector<int>> &mp, int i, vector<int> &visited, int parent)
{
    visited[i]=1;
    for(auto x: mp[i])
    {
        if(visited[x]!=1)
        {
            if(DFSRec(mp,x,visited,i))
            return true;
        }
        else if(x!=parent)
        return true;
    }
    return false;
}

bool dfsTraverse(unordered_map<int,vector<int>> &mp,int n)
{
    vector<int> visit(n);
    for(int i=0;i<n;i++)
    {
        if(DFSRec(mp,i,visit,-1))
        return true;
    }
    return false;
}