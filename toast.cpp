#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;
int N, L, R, ans;
bool flag;

vector<vector<int>> map;
vector<vector<int>> mapcpy;
vector<vector<bool>> visited;

int mv1[4] = { -1, 1, 0, 0 };
int mv2[4] = { 0, 0, -1, 1 };

void bfs(int a, int b) {
    vector<pair<int, int>> egg;
    queue<pair<int, int>> q;
    q.push({ a, b });
    visited[a][b] = true;
    flag = true;

    int sum = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        sum += map[x][y];
        egg.push_back({ x, y });

        for (int i = 0; i < 4; i++) {
            int nx = x + mv1[i];
            int ny = y + mv2[i];

            if (0 <= nx && nx < N && 0 <= ny && ny < N) {
                int diff = abs(map[x][y] - map[nx][ny]);
                if (!visited[nx][ny] && L <= diff && diff <= R) {
                    visited[nx][ny] = true;
                    q.push({ nx, ny });
                }
            }
        }
    }

    if (egg.size() > 1) {
        flag = false;
        int aver = sum / egg.size();

        for (int i = 0; i < egg.size(); i++) {
            int x = egg[i].first;
            int y = egg[i].second;
            mapcpy[x][y] = aver;
        }
        egg.clear();
    }
}

void change() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[i][j] = mapcpy[i][j];
            visited[i][j] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int cnt = 0;
    cin >> N >> L >> R;
    map.resize(N, vector<int>(N));
    mapcpy.resize(N, vector<int>(N));
    visited.resize(N, vector<bool>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            mapcpy[i][j] = map[i][j];
        }
    }

    while (1) {
        cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j]) {
                    bfs(i, j);
                    if (flag) ++cnt;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << mapcpy[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n\n";

        if (cnt == N * N) break;
        else ans++;
        change();
    }

    cout << ans;

    return 0;
}