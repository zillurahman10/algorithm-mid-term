#include <bits/stdc++.h>
using namespace std;

const long long int INF = 1e18;
const long long int N = 1005;
vector<pair<long long int, long long int>> adj[N];

void dijkstra(long long int src, long long int n, vector<long long int> &dist)
{
    priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> pq;
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        long long int u = pq.top().second;
        long long int d = pq.top().first;
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto edge : adj[u])
        {
            long long int v = edge.first;
            long long int w = edge.second;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    long long int n, m;
    cin >> n >> m;

    for (long long int i = 0; i < m; i++)
    {
        long long int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }

    long long int source;
    cin >> source;

    long long int t;
    cin >> t;

    while (t--)
    {
        long long int dest, maxCost;
        cin >> dest >> maxCost;

        vector<long long int> dist(n + 1, INF);
        dijkstra(source, n, dist);

        if (dist[dest] <= maxCost)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
