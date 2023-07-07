#include<bits/stdc++.h>
using namespace std;
// for undirected list

unordered_map<int,vector<int>> addNode(int n, vector<vector<int>> &v)
{
    unordered_map<int,vector<int>> mp;
    // for(int i=0;i<n;i++)
    // mp[i].push_back(i);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=j && v[i][j]==1)
            mp[i].push_back(j);
        }
    }
    return mp;
}

void dfs_preorder(unordered_map<int,vector<int>> &mp, vector<int> &mark, int i)
{
    cout << i << " ";
    mark[i]=1;
    for(auto x : mp[i])
    {
        if(mark[x]!=1)
        dfs_preorder(mp,mark,x);
    }
}
void dfs_postorder(unordered_map<int,vector<int>> &mp, vector<int> &mark, int i)
{
    mark[i]=1;
    for(auto x : mp[i])
    {
        if(mark[x]!=1)
        dfs_postorder(mp,mark,x);
    }
    cout << i << " ";
}

void dfs_iter_pre(unordered_map<int,vector<int>> &mp, int n)
{
    vector<int> mark(n);
    stack<int> st;
    st.push(0);
    while(!st.empty())
    {
        int i=st.top();
        st.pop();
        if(mark[i]!=1)
        {
            cout << i << " ";
            mark[i]=1;
            for(auto x: mp[i])
            {
                if(mark[x]!=1)
                st.push(x);
            }
        }
    }
}

void bfs(unordered_map<int,vector<int>> &mp, int n)
{
    vector<int> mark(n);
    queue<int> q;
    q.push(0);
    while(!q.empty())
    {
        int i= q.front();
        q.pop();
        if(mark[i]!=1)
        {
            cout << i << " ";
            mark[i]=1;
            for(auto x: mp[i])
            {
                if(mark[x]!=1)
                q.push(x);
            }
        }
    }
    cout << endl;
}

vector<int> shortest(unordered_map<int,vector<int>> &mp, int n, int source)
{
    vector<int> dist(n);
    vector<int> mark(n);
    mark[source]=1;
    queue<int> q;
    q.push(source);
    while(!q.empty())
    {
        int u =q.front();
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
    return dist;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v;
    for(int i=0;i<n;i++)
    {
        vector<int> w;
        for(int j=0;j<n;j++)
        {
            int d;
            cin >>d;
            w.push_back(d);
        }
        v.push_back(w);
    }

    unordered_map<int,vector<int>> mp= addNode(n,v);
    vector<int> dist=shortest(mp,n,0);
    for(int i=0;i<n;i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
    // vector<int> mark(n);
    // dfs_preorder(mp,mark,0);
    // cout<< endl;
    // dfs_iter_pre(mp,n);
    // cout << endl;
    // vector<int> mark2(n);
    // dfs_postorder(mp,mark2,0);
    // cout << endl;

    dist=shortest(mp,n,2);
    for(int i=0;i<n;i++)
    {
        cout << dist[i] << " ";
    }
}