#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;

struct State {
    int x, y;
    int sm;
    int dir;

    State(int a, int b, int c, int d) {
        x = a; y = b; sm = c; dir = d;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(false);

    freopen("dream.in", "r", stdin); freopen("dream.out", "w", stdout);

    int N, M; cin >> N >> M;
    int maze[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cin >> maze[i][j];
    }

    int pos[N][M][2][4];
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) for (int a = 0; a < 2; a++) for (int b = 0; b < 4; b++) pos[i][j][a][b] = INT_MAX;
    pos[0][0][0][0] = pos[0][0][0][1] = pos[0][0][0][2] = pos[0][0][0][3] = 0;

    //pos:
    //position (i,j), then orange smell or not (1 or 0), then direction: +x 0, +y 1, -x 2, -y 3. Contains min
    /*
       o --> +y
       |
       v +x
    */
   
    queue<State> q;
    q.push(State(0, 0, 0, 0));
    q.push(State(0, 0, 0, 1));
    q.push(State(0, 0, 0, 2));
    q.push(State(0, 0, 0, 3));

    while (!q.empty()) {
        State s = q.front();
        q.pop();
        int sDist = pos[s.x][s.y][s.sm][s.dir];

        if (s.x == N-1 && s.y == M-1) {
            cout << sDist << "\n";
            return 0;
        }

        int newSmell = s.sm;

        if (maze[s.x][s.y] == 4) {
            newSmell = 0;
            State nex(s.x, s.y, newSmell, s.dir);
            if (s.dir == 0) nex.x++;
            else if (s.dir == 1) nex.y++;
            else if (s.dir == 2) nex.x--;
            else nex.y--;
            if (nex.x >= 0 && nex.x < N && nex.y >= 0 && nex.y < M && maze[nex.x][nex.y] != 0 && (maze[nex.x][nex.y] != 3 || newSmell)) {
                if (sDist+1 < pos[nex.x][nex.y][nex.sm][nex.dir]) {
                    pos[nex.x][nex.y][nex.sm][nex.dir] = sDist+1;
                    q.push(nex);
                }
                continue;
            }
        }

        //now we can go wherever
        if (maze[s.x][s.y] == 2) newSmell = 1;

        for (int i = 0; i < 4; i++) {
            State nex(s.x, s.y, newSmell, i);
            if (i == 0) nex.x++;
            else if (i == 1) nex.y++;
            else if (i == 2) nex.x--;
            else nex.y--;

            if (nex.x < 0 || nex.x >= N || nex.y < 0 || nex.y >= M) continue;
            if (maze[nex.x][nex.y] == 0 || (maze[nex.x][nex.y] == 3 && !newSmell)) continue;
            if (sDist+1 < pos[nex.x][nex.y][nex.sm][nex.dir]) {
                pos[nex.x][nex.y][nex.sm][nex.dir] = sDist+1;
                q.push(nex);
            }
        }
    }

    cout << "-1\n";
}