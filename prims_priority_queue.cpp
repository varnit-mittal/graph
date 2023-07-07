#include<bits/stdc++.h>
using namespace std;

void addNode(unordered_map<int,vector<pair<int,int>>> &mp, int i, int value, int wieght)
{
    mp[i].push_back(make_pair(value,wieght));
    mp[value].push_back(make_pair(i,wieght));
}

int prims(unordered_map<int,vector<pair<int,int>>> &mp, int n)
{
    vector<int> MST(n,-1);
    vector<int> key(n, INT_MAX);
    key[0]=0;
    vector<bool> inMST(n,false);
    int res=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0,0));
    while(!pq.empty())
    {
        int u= pq.top().second;
        pq.pop();
        if(inMST[u])
        continue;
        inMST[u]=true;

        for(auto i : mp[u])
        {
            int v= i.first;
            int wieght= i.second;
            if(inMST[v]==false && key[v]>wieght)
            {
                key[v]=wieght;
                pq.push(make_pair(key[v],v));
                MST[v]=u;
            }
        }
    }
    for(auto i=key.begin();i!=key.end();i++)
    res+=*i;
    return res;
}

int main()
{
    unordered_map<int,vector<pair<int,int>>> mp;
    int n =9;
    while(1)
    {
        int i;
        cin >> i;
        if(i==-1)
        break;
        int val;
        cin >> val;
        int w;
        cin >> w;
        addNode(mp,i,val,w);
    }
    cout << prims(mp,n) << endl;
}