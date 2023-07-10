#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
class edge
{
public:
    int u, v, w;
};
void addEdge(vector<edge> &v, int x, int y, int w)
{
    v.push_back({w, x, y});
}

typedef struct Edge
{
    vector<int> parent;
    vector<int> rank;

    Edge(int n)
    {
        for (int i = 0; i < n; i++)
        {
            parent.push_back(-1);
            rank.push_back(0);
        }
    }

    int find(int i)
    {
        if (parent[i] == -1)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x != y)
        {
            if (rank[x] < rank[y])
                parent[x] = y;
            else if (rank[x] > rank[y])
                parent[y] = x;
            else
            {
                parent[y] = x;
                rank[x] += 1;
            }
        }
    }
} Edge;

int kruskal(vector<edge> &v, int n, Edge *e, int s, int res)
{
    for (int i = 0; s < n - 1; i++)
    {
        if (e->find(v[i].u) != e->find(v[i].v))
        {
            e->unite(v[i].u, v[i].v);
            res += v[i].w;
            s++;
        }
    }
    return res;
}
bool comp(edge a, edge b)
{
    return a.w < b.w;
}
int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<edge> inp;
    vector<edge> v;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        x--;
        y--;
        addEdge(inp, x, y, w);
        addEdge(v, x, y, w);
    }
    vector<int> result;
    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < m; i++)
    {
        int res = 0;
        int s = 1;
        Edge *e = new Edge(n);
        e->unite(inp[i].u, inp[i].v);
        res += inp[i].w;
        result.push_back(kruskal(v, n, e, s, res));
    }
    for (int i = 0; i < m; i++)
    {
        cout << result[i] << endl;
    }
}