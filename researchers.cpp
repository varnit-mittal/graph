#include <bits/stdc++.h>
using namespace std;

void addNode(unordered_map<int, vector<int>> &mp, int i, int value)
{
    mp[i].push_back(value);
    mp[value].push_back(i);
}

void dfs(unordered_map<int, vector<int>> &mp, vector<int> &mark, int j, vector<int> &nums)
{
    stack<int> st;
    st.push(j);
    int count = 0;
    while (!st.empty())
    {
        int i = st.top();
        st.pop();
        if (mark[i] != 1)
        {
            count++;
            mark[i] = 1;
            for (auto x : mp[i])
            {
                if (mark[x] != 1)
                    st.push(x);
            }
        }
    }
    cout << endl;
    nums.push_back(count);
}

vector<int> groups(unordered_map<int, vector<int>> &mp, int n)
{
    vector<int> mark(n);
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        if (mark[i] != 1)
            dfs(mp, mark, i, nums);
    }
    return nums;
}

int noGroup(vector<int> &nums)
{
    int s = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] >= 2)
        {
            s = s + (nums[i] * (nums[i]-1))/2;
        }
        else
            s += 0;
    }
    return s;
}

int main()
{
    int n, p;
    cin >> n >> p;
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < p; i++)
    {
        int j, val;
        cin >> j >> val;
        addNode(mp, j, val);
    }
    if (n == 1)
        cout << 0 << endl;
    else
    {
        vector<int> v = groups(mp, n);
        int c= (n * (n-1))/2 ;
        // cout << c << endl;
        int x= noGroup(v);
        // cout << x << endl;
        cout << c- x << endl;
    }
}