#include <bits/stdc++.h>
using namespace std;

// void addNode(unordered_map<int, vector<int>> &mp, int index, int value)
// {
//     mp[index].push_back(value);
//     // mp[value].push_back(index);
// }
void addNode2(unordered_map<int, vector<int>> &mp, int index, int value)
{
    mp[index].push_back(value);
    mp[value].push_back(index);
}

void flower_util(unordered_map<int, vector<int>> &mp, vector<int> &v, int i, vector<int> &mark)
{
    queue<int> st;
    st.push(i);
    while (!st.empty())
    {
        int val = st.front();
        st.pop();
        if (mark[val] != 1)
        {
            mark[val] = 1;
            v[val] = 1;
            vector<int> temp;
            for (auto x : mp[val])
            {
                temp.push_back(x);
                cout << v[val] << " ";
                cout <<"Val = "<< val<< " " <<x <<" "<<  v[x]<< endl;
                if(mark[x]!=1)
                st.push(x);
            }
            sort(temp.begin(), temp.end());
            for (auto x : temp)
                if (v[x] == v[val])
                    v[val]++;
        }
    }
}

vector<int> flower(unordered_map<int, vector<int>> &mp, int n)
{
    vector<int> mark(n + 1);
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (mark[i] != 1)
            flower_util(mp, ans, i, mark);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int t;
    cin >> t;
    // unordered_map<int, vector<int>> mp;
    unordered_map<int, vector<int>> graph;
    vector<int> v;
    for (int i = 0; i < 2 * t; i++)
    {
        int d;
        cin >> d;
        v.push_back(d);
    }
    for (int i = 0; i < 2 * t; i += 2)
    {
        addNode2(graph, v[i], v[i + 1]);
    }
    vector<int> ans = flower(graph, n);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}