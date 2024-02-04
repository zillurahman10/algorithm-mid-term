#include <iostream>
#include <vector>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int x, int y)
{
    visited[x][y] = true;

    for (int k = 0; k < 4; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == '.' && !visited[nx][ny])
        {
            dfs(grid, visited, nx, ny);
        }
    }
}

bool inSameComponent(vector<vector<char>> &grid, pair<int, int> S, pair<int, int> D)
{
    int N = grid.size();
    int M = grid[0].size();

    vector<vector<bool>> visited(N, vector<bool>(M, false));

    dfs(grid, visited, S.first, S.second);

    return visited[D.first][D.second];
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<char>> grid(N, vector<char>(M));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> grid[i][j];
        }
    }

    int Sx, Sy, Dx, Dy;
    cin >> Sx >> Sy >> Dx >> Dy;

    pair<int, int> S = make_pair(Sx, Sy);
    pair<int, int> D = make_pair(Dx, Dy);

    if (inSameComponent(grid, S, D))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
