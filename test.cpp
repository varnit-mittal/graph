#include <bits/stdc++.h>
using namespace std;

void addNode(unordered_map<int, vector<int>> &mp, int i, int val)
{
    mp[i].push_back(val);
}

void addNode2(unordered_map<int, vector<pair<int, int>>> &mp, int i, int val)
{
    mp[i].push_back(make_pair(val, 1));
}

vector<int> dijkstra(unordered_map<int, vector<pair<int, int>>> &mp, int n, int mid)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n, INT_MAX);
    dist[mid] = 0;
    pq.push(make_pair(0, mid));
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (auto x : mp[u])
        {
            int v = x.first;
            int wieght = x.second;
            if (dist[v] % 1000 > dist[u] % 1000 + wieght)
            {
                dist[v] = dist[u] + wieght;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    return dist;
}

void minSweets_utils(unordered_map<int, vector<int>> &mp, int mid, int dest, vector<int> &val, vector<int> &sweets, int n, vector<int> &dist)
{
    queue<pair<int, int>> q;
    q.push(make_pair(sweets[mid], mid));
    int u = INT_MAX;
    // cout << dest << endl;
    for (int i = 0; i < dist[dest]; i++)
    {
        vector<pair<int, int>> vtemp;
        while (!q.empty())
        {
            pair<int, int> temp = q.front();
            q.pop();
            vtemp.push_back(temp);
        }
        for (int i = 0; i < vtemp.size(); i++)
        {
            int v = vtemp[i].first;
            int j = vtemp[i].second;
            // cout << v << " " << j << endl;
            for (auto x : mp[j])
            {
                // cout <<j<<" "<< v<< " " <<x<< endl;
                q.push(make_pair(max(v, sweets[x]), x));
            }
        }
    }
    while (!q.empty())
    {
        // cout << q.front().first << " "<< q.front().second << endl;
        if (q.front().second == dest)
            u = min(u, q.front().first);
        q.pop();
    }
    // cout << "************\n";
    val.push_back(u);
}

int main()
{
	int t;
	cin >>t;
	while(t--)
	{
		int n, m, mid;
		cin >> n >> m >> mid;
		mid--;
		vector<int> sweets;
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			sweets.push_back(a);
		}
		unordered_map<int, vector<pair<int, int>>> mp;
		unordered_map<int, vector<int>> route;
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			addNode(route, a, b);
			addNode2(mp, a, b);
		}
		vector<int> dist = dijkstra(mp, n, mid);
		vector<int> val;
		for (int i = 0; i < n; i++)
		{
			minSweets_utils(route, mid, i, val, sweets, n, dist);
		}
		for (int i = 0; i < n; i++)
		{
			cout << val[i] << " ";
		}
		cout << endl;
	}
}