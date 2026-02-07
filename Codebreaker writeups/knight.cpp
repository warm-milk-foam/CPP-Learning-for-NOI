#include <<bits/stdc++.h>>
using namespace std;
// https://codebreaker.xyz/problem/knightmoves
int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int board_size;
    cin >> board_size;

    vector<vector<int>> board(board_size, vector<int>(board_size, -1));
    vector<vector<bool>> blocked(board_size, vector<bool>(board_size, false));

    int sx, sy;
    cin >> sx >> sy;
    sx--; sy--;

    int tx, ty;
    cin >> tx >> ty;
    tx--; ty--;

    int T;
    cin >> T;
    // check if the tile is blocked
    for (int i = 0; i < T; i++) {
        int x, y;
        cin >> x >> y;
        blocked[x-1][y-1] = true;
    }


    if (blocked[sx][sy] || blocked[tx][ty]) {
        cout << -1 << "\n";
        return 0;
    }

    queue<pair<int,int>> q;
    q.push({sx, sy});
    board[sx][sy] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == tx && y == ty) {
            cout << board[x][y] << "\n";
            return 0;
        }

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= board_size || ny < 0 || ny >= board_size)
                continue;
            if (blocked[nx][ny])
                continue;
            if (board[nx][ny] != -1)
                continue;

            board[nx][ny] = board[x][y] + 1;
            q.push({nx, ny});
        }
    }

    cout << -1 << "\n";
}
