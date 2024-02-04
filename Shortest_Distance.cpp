#include <bits/stdc++.h>

using namespace std;

const long long N = 1e16;

vector<vector<long long>> floydWarshall(int n, const vector<vector<long long>> &edges)
{
    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, N));

    for (const auto &edge : edges)
    {
        int a = edge[0], b = edge[1];
        long long w = edge[2];
        dist[a][b] = min(dist[a][b], w);
    }

    for (int i = 1; i <= n; ++i)
    {
        dist[i][i] = 0;
    }

    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (dist[i][k] != N && dist[k][j] != N && dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    return dist;
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<vector<long long>> edges(e, vector<long long>(3));

    for (int i = 0; i < e; ++i)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    vector<vector<long long>> shortestPaths = floydWarshall(n, edges);

    int q;
    cin >> q;

    while (q--)
    {
        int x, y;
        cin >> x >> y;

        if (shortestPaths[x][y] == N)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << shortestPaths[x][y] << endl;
        }
    }

    return 0;
}
