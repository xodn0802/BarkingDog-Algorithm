#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int board[53][53];
int ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);

	int n, m, d;
	int x, y;

	cin >> n >> m;

	cin >> x >> y >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	while (true) {
		if (board[x][y] == 0) ans++;
		board[x][y] = -1;
		bool clean = false;
		for (int i = 0; i < 4; i++) {
			d = (d + 3) % 4;
			if (board[x + dx[d]][y + dy[d]] == 0) {
				x += dx[d];
				y += dy[d];
				clean = true;
				break;
			}
		}
		if (clean) continue;
		if (board[x - dx[d]][y - dy[d]] == 1) break;
		x -= dx[d];
		y -= dy[d];
	}

	cout << ans;




	return 0;
}
