#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

bool isValid(vector<vector<int>> &v, int row, int col)
{
    return (row>=0 && col >=0 && row<v.size() && col<v[0].size());
}

vector<pair<int,int>> nieghbours(vector<vector<int>> &v,int row, int col)
{
    vector<pair<int,int>> ans;
    vector<pair<int,int>> index={{row+1,col},{row-1,col},{row,col+1},{row,col-1}};
    for(int i=0;i<4;i++)
    {
        pair<int,int> p;
        p.first= index[i].first;
        p.second=index[i].second;
        if(isValid(v,p.first,p.second))
        {
            if(v[p.first][p.second]==1)
            ans.push_back(p);
        }
    }
    return ans;
}

void floodFill(vector<vector<int>> &v, int row, int col, unordered_set<int> &mark, int m, int n)
{
    // cout << " yes"<< endl;
    queue<pair<int,int>> q;
    q.push({row,col});
    while(!q.empty())
    {
        row=q.front().first;
        col=q.front().second;
        q.pop();
        mark.insert(row*n+col);
        v[row][col]=2;
        vector<pair<int,int>> sol= nieghbours(v,row,col);
        for(int i=0;i<sol.size();i++)
        {
            if(mark.find((sol[i].first)*n+sol[i].second)==mark.end())
            {
                q.push(sol[i]);
            }
        }
    }
}

int islandCount(vector<vector<int>> &v)
{
    int count=0;
    unordered_set<int> mark;
    int n=v[0].size();
    for(int row=0; row < v.size();row++)
    {
        for(int col=0;col<v[0].size();col++)
        {
           if(mark.find(row*n+col)==mark.end())
           {
            if(v[row][col]==1)
            {
                floodFill(v,row,col,mark,v.size(), n);
                count++;
            }
           }
        }
    }
    return count;
}

int main()
{
    int m;
    cin >> m;
    int n;
    cin >> n;
    vector<vector<int>> v;
    for(int i=0;i<m;i++)
    {
        vector<int> temp;
        for(int j=0;j<n;j++)
        {
            int d;
            cin >> d;
            temp.push_back(d);
        }
        v.push_back(temp);
    }

    // cout << v.size() << " " << v[0].size()<< endl;
    cout << islandCount(v) << endl;
    for(int i=0;i< m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}