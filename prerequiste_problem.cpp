#include <bits/stdc++.h>
using namespace std;

void addNode(unordered_map<int, vector<int>> &mp, int index, int value)
{
    mp[index].push_back(value);
}

bool isPrerequiste(unordered_map<int, vector<int>> &mp, int i, int j, int n)
{
    vector<int> mark(n);
    stack<int> st;
    st.push(i);
    while (!st.empty())
    {
        int val = st.top();
        // cout << val << " ";
        st.pop();
        if (mark[val] != 1)
        {
            if (val == j)
                return true;
            mark[val] = 1;
            for (auto x : mp[val])
            {
                if (mark[x] != 1)
                    st.push(x);
            }
        }
    }
    // cout << 2 << endl;
    return false;
}

int main()
{
    int n;
    cin >> n;
    int t;
    cin >> t;
    unordered_map<int, vector<int>> mp;
    vector<int> v;
    for (int i = 0; i < 2 * t; i++)
    {
        int d;
        cin >> d;
        v.push_back(d);
    }
    for (int i = 0; i < 2 * t; i += 2)
    {
        // cout << i << " " <<v[i] << endl;
        addNode(mp, v[i], v[i + 1]);
    }

    // for(int i=0;i<2*t;i++)
    // {
    //     // cout << i << endl;
    //     for(auto x: mp[i])
    //     // cout << x <<" ";
    //     // cout << endl;
    // }
    int m;
    cin >> m;
    vector<int> ans;
    // cout << m << endl;
    for (int i = 0; i < 2 * m; i++)
    {
        int d;
        cin >> d;
        ans.push_back(d);
    }

    // cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i += 2)
    {
        if (t == 0)
            cout << 0 << " ";
        else if (isPrerequiste(mp, ans[i], ans[i + 1], n))
            cout << 1 << " ";
        else
            cout << 0 << " ";
    }
    cout << endl;
    return 0;
}