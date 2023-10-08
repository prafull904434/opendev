#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:
    vector<int> parent;

    DSU(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            parent[rootX] = rootY;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    DSU dsu(n);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        dsu.unite(x, y);
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (dsu.find(x) == dsu.find(y))
        {
            cout << "They belong to the same set." << endl;
        }
        else
        {
            cout << "They belong to different sets." << endl;
        }
    }

    return 0;
}
