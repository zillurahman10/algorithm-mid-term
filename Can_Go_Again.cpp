#include <bits/stdc++.h>
using namespace std;

const int N = 1e18;

vector<int> u, v, w;

void bellmanFord(int src, int n, vector<int> &dist)
{
    dist[src] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < u.size(); j++)
        {
            if (dist[u[j]] != N && dist[u[j]] + w[j] < dist[v[j]])
            {
                dist[v[j]] = dist[u[j]] + w[j];
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b, wt;
        cin >> a >> b >> wt;
        u.push_back(a);
        v.push_back(b);
        w.push_back(wt);
    }

    int source;
    cin >> source;

    vector<int> dist(n + 1, N);
    bellmanFord(source, n, dist);

    int t;
    cin >> t;

    while (t--)
    {
        int dest;
        cin >> dest;

        for (int j = 0; j < u.size(); j++)
        {
            if (dist[u[j]] != N && dist[u[j]] + w[j] < dist[v[j]])
            {
                cout << "Negative Cycle Detected" << endl;
                return 0;
            }
        }

        if (dist[dest] == N)
        {
            cout << "Not Possible" << endl;
        }
        else
        {
            cout << dist[dest] << endl;
        }
    }

    return 0;
}
