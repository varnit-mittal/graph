#include<bits/stdc++.h>
using namespace std;

void addNode(unordered_map<int,vector<int>> &mp, int i, int value)
{
    mp[i].push_back(value);
}

void countInorder(unordered_map<int,vector<int>> &mp, vector<int> &inorder, int i,vector<int> &mark)
{
    mark[i]=1;
    for(auto x: mp[i])
    {
        // cout <<i<<" "<< x << " ";
        inorder[x]+=1;
        // cout <<inorder[x]<<endl;
        if(mark[x]!=1)
        countInorder(mp,inorder,x,mark);
    }
}

vector<int> countComp(unordered_map<int,vector<int>> &mp, int n)
{
    vector<int> inorder(n);
    vector<int> mark(n);
    for(int i=0;i<n;i++)
    {
        if(mark[i]!=1)
        countInorder(mp,inorder,i,mark);
    }
    return inorder;
}

int main()
{
    int n=5;
    unordered_map<int,vector<int>> mp;
    while(1)
    {
        int i;
        cin>> i;
        if(i==-1)
        break;
        int value;
        cin >> value;
        addNode(mp,i,value);
    }
    vector<int> inorder=countComp(mp,n);
    for(int i=0;i<n;i++)
    cout << inorder[i] << " ";
}