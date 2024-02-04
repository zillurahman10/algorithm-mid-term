#include <bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, int N, int M, bool visited[][100])
{
    return (x >= 0 && x < N && y >= 0 && y < M && !visited[x][y]);
}

int minStepsForKnight(int N, int M, int srcX, int srcY, int destX, int destY)
{
    bool visited[N][100] = {false};
    queue<pair<int, int>> q;
    int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

    q.push({srcX, srcY});
    visited[srcX][srcY] = true;
    int level = 0;

    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == destX && y == destY)
            {
                return level;
            }

            for (int k = 0; k < 8; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (isValid(nx, ny, N, M, visited))
                {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
        level++;
    }

    return -1;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N, M;
        cin >> N >> M;

        int srcX, srcY, destX, destY;
        cin >> srcX >> srcY >> destX >> destY;

        cout << minStepsForKnight(N, M, srcX, srcY, destX, destY) << endl;
    }

    return 0;
}
