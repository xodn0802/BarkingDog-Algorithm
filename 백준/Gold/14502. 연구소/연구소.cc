#define _CRT_SECURE_NO_WARNINGS
#define X first
#define Y second
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> Q;
vector < pair<int, int>> empty_box;
int n, m;
int board[10][10];
int board2[10][10];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) {
				empty_box.push_back({ i,j });
			}
			
		}
	}
	int K = empty_box.size();
	int cnt = 0;
	for (int i = 0; i < K; i++) {
		for (int j = i + 1; j < K; j++) {
			for (int z = j + 1; z < K; z++) {
				int ans = 0;
				int x1 = empty_box[i].X;
				int y1 = empty_box[i].Y;
				int x2 = empty_box[j].X;
				int y2 = empty_box[j].Y;
				int x3 = empty_box[z].X;
				int y3 = empty_box[z].Y;
				for (int p = 0; p < n; p++) {
					for (int q = 0; q < m; q++) {
						board2[p][q] = board[p][q];
						if (board2[p][q] == 2) Q.push({ p,q });
					}
				}
				board2[x1][y1] = 1;
				board2[x2][y2] = 1;
				board2[x3][y3] = 1;
				while (!Q.empty()) {
					auto cur = Q.front();
					Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (board2[nx][ny] == 1 || board2[nx][ny] == 2) continue;
						Q.push({ nx,ny });
						board2[nx][ny] = 2;
					}
				}
				for (int p = 0; p < n; p++) {
					for (int q = 0; q < m; q++) {
						if (board2[p][q] == 0) ans++;
					}
				}
				if (cnt <= ans) {
					cnt = ans;
				}

			}
		}
	}
	cout << cnt;


	return 0;
}