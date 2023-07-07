#include<bits/stdc++.h>
using namespace std;

bool DFSRec(unordered_map<int,vector<int>> &mp, int i, vector<int> & visit, vector<int> &recStack)
{
    visit[i]=1;
    recStack[i]=1;
    for(auto x: mp[i])
    {
        if(visit[x]==false && DFSRec(mp,x,visit,recStack))
        return true;
        else if(recStack[x])
        return true;
    }
    recStack[i]=0;
    return false;
}

bool cycle(int n, unordered_map<int,vector<int>> &mp)
{
    vector<int> vist(n);
    vector<int> recStack(n);
    for(int i=0;i<n;i++)
    {
        if(vist[i]==0)
        {
            if(DFSRec(mp,i,vist,recStack))
            return true;
        }
    }
    return false; 
}