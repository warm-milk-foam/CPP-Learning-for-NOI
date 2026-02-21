#include <bits/stdc++.h>
using namespace std;

int main() {
    int X, Y, Mx, My;
    cin >> X >> Y >> Mx >> My;

    vector<vector<int>> field(Y, vector<int>(X, 1)); // 1 = grass, 0 = rock, +1 is sussy weed

    // format the grid properly
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            char input;
            cin >> input;
            if (input == '*') field[i][j] = 0; // rock
        }
    }

    // convert bottom-left to vector indices pmo
    int startX = Mx - 1;
	int startY = Y - My;

    // check if start is not rock
    if (field[startY][startX] == 0) {
        cout << 0 << endl; // cant grow
        return 0;
    }

    field[startY][startX] = 2; // milkweed starts here

    queue<pair<int,int>> q;
    q.push({startY, startX});

    vector<pair<int,int>> moves = {
        {-1, -1}, {-1, 0}, {-1, 1}, 
        {0, -1},           {0, 1}, 
        {1, -1},  {1, 0},  {1, 1}
    };

    int weeks = -1;

    while (!q.empty()) {
        int sz = q.size();
        weeks++;

        for (int i = 0; i < sz; i++) {
            auto [y, x] = q.front(); q.pop();

            for (auto [dy, dx] : moves) {
                int ny = y + dy;
                int nx = x + dx;

                if (ny >= 0 && ny < Y && nx >= 0 && nx < X && field[ny][nx] == 1) { // if it doesn't exceed boundaries and the spot is a grass
                    field[ny][nx] = 2;
                    q.push({ny, nx});
                }
            }
        }
    }
	// i recycled this code from the simp challenge lmao
    cout << weeks << endl;
    
    // yay it works now!!!
}
