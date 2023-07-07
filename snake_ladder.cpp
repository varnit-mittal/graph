#include<bits/stdc++.h>
using namespace std;

int minMoves(unordered_map<int,int> &mp)
{
    int dist;
    queue<pair<int,int>> q;
    q.push(make_pair(0,1));
    while(!q.empty())
    {
        pair<int,int> qe=q.front();
        q.pop();
        dist=qe.first;
        int vertex=qe.second;
        if(vertex==30)
        {
            return dist;
        }
        for(int i=vertex+1;i<vertex+7;i++)
        {
            int j=i;
            int d=dist+1;
            if(mp.find(i)!=mp.end())
            j=mp[i];
            q.push(make_pair(d,j));
        }
    }
    return dist;
}

int main()
{
    unordered_map<int,int> mp;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>> a>> b;
        mp[a]=b;
    }
    cout << minMoves(mp) << endl;
}