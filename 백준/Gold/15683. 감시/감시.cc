#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
#define X first
#define Y second

int n, m;
int board[10][10];
int board2[10][10];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

vector<pair<int, int>> cctv;

void draw(int x, int y, int dir) {
	dir %= 4;
	while (true) {
		x += dx[dir];
		y += dy[dir];
		if (x < 0 || x >= n || y < 0 || y >= m) return;
		if (board2[x][y] == 6) return;
		if (board2[x][y] == 0) board2[x][y] = -1;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	cin >> n >> m;
	int nm = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] != 0 && board[i][j] != 6) cctv.push_back({i,j});
			if (board[i][j] == 0) nm++;
		}
	}
	for (int tmp = 0; tmp < (1 << (2 * cctv.size()));tmp++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				board2[i][j] = board[i][j];
			}
		}
		int brute = tmp;
		for (int i = 0; i < cctv.size(); i++) {
			int dir = brute % 4;
			brute /= 4;
			int x = cctv[i].X;
			int y = cctv[i].Y;
			if (board[x][y] == 1) {
				draw(x, y, dir);
			}
			else if (board[x][y] == 2) {
				draw(x, y, dir);
				draw(x, y, dir + 2);
			}
			else if (board[x][y] == 3) {
				draw(x, y, dir);
				draw(x, y, dir + 1);
			}
			else if (board[x][y] == 4) {
				draw(x, y, dir);
				draw(x, y, dir + 1);
				draw(x, y, dir + 2);
			}
			else if (board[x][y] == 5) {
				draw(x, y, dir);
				draw(x, y, dir + 1);
				draw(x, y, dir + 2);
				draw(x, y, dir + 3);
			}
		}
		int val = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				val += (board2[i][j] == 0);
			}
		}
		nm = min(val, nm);

	}
	cout << nm;
	

}