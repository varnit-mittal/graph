#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

void addNode(int i, int val, unordered_map<int,vector<int>> &mp)
{
    mp[i].push_back(val);
}

void tarjan(unordered_map<int,vector<int>> &mp, unordered_map<int,vector<int>> &strong, vector<int> &disc, vector<bool> &found, vector<int> &low, int &w, int u,int &time, stack<int> &st)
{
    disc[u]=low[u]=++time;
    st.push(u);
    found[u]=true;
    for(auto i: mp[u])
    {
        if(disc[i]==-1)
        {
            tarjan(mp,strong,disc,found,low,w,i,time,st);
            low[u]=min(low[u],low[i]);
        }
        else if(found[i])
        {
            low[u]=min(low[u],disc[i]);
        }
    }
    if(disc[u]==low[u])
    {
        while(1)
        {
            int v=st.top();
            st.pop();
            strong[w].push_back(v);
            found[v]=false;
            if(v==u)
            break;
        }
        w++;
    }
}

int main()
{
    set<int> s;
    unordered_map<int,vector<int>> mp;
    while(1)
    {
        int i;
        cin >> i;
        if(i==-1)
        break;
        int val;
        cin >> val;
        addNode(i,val,mp);
        s.insert(i);
        s.insert(val);
    }
    int n=0;
    for(auto i: s)
    {
        n=i+1;
    }
    vector<bool> found(n,false);
    vector<int> disc(n,-1);
    vector<int> low(n,-1);
    unordered_map<int,vector<int>> strong;
    int w=0;
    int time=0;
    stack<int> st;
    tarjan(mp,strong,disc,found,low,w,0,time,st);
    for(int i=0;i<w;i++)
    {
        for(auto x: strong[i])
        cout << x << " ";
        cout << endl;
    }

}