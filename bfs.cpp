#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    queue<pair<int, int>> q;
    vector<vector<int>> dist(m, vector<int>(n, -1));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == 0) {
                dist[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }
    }

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        int i = curr.first, j = curr.second;

        for (int d = 0; d < 4; ++d) {
            int ni = i + dx[d];
            int nj = j + dy[d];
            if (ni >= 0 && nj >= 0 && ni < m && nj < n && dist[ni][nj] == -1) {
                dist[ni][nj] = dist[i][j] + 1;
                q.push(make_pair(ni, nj));
            }
        }
    }

    return dist;
}

int main() {
    vector<vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };

    vector<vector<int>> result = updateMatrix(mat);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[0].size(); ++j)
            cout << result[i][j] << " ";
        cout << endl;
    }

    return 0;
}
