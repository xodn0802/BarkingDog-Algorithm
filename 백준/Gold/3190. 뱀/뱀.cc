#define _CRT_SECURE_NO_WARNINGS
#define X first
#define Y second
#include <iostream>
#include <queue>
#include <string>
#include <stack>
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int board[102][102];
int dirextion[102];
char RL[102];
queue <pair<int, int>> Q;
int n, k, l;
int c;
int ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ax, ay;
	int dir = 0;

	//freopen("input.txt", "r", stdin);

	cin >> n >> k;
	
	for (int i = 0; i < k; i++) {
		cin >> ax >> ay;
		board[ax - 1][ay - 1] = 1;
	}
	Q.push({ 0,0 });
	board[0][0] = -1;
	cin >> l;
	for (int i = 0; i < l; i++) {
		cin >> dirextion[i];
		cin >> RL[i];
	}
	while (true) {
		if (ans == dirextion[c]) {
			if (RL[c] == 'L') {
				dir = (dir + 3) % 4;
				c++;
			}
			else {
				dir = (dir + 1) % 4;
				c++;
			}
		}
		auto cur = Q.back();
		int nx = cur.X + dx[dir];
		int ny = cur.Y + dy[dir];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] == -1) {
			ans++;
			break;
		}
		else if (board[nx][ny] == 1) {
			Q.push({ nx,ny });
			board[nx][ny] = -1;
			ans++;
		}
		else if (board[nx][ny] == 0) {
			auto cur2 = Q.front();
			Q.pop();
			board[cur2.X][cur2.Y] = 0;
			Q.push({ nx,ny });
			board[nx][ny] = -1;
			ans++;
		}
	}

	cout << ans;

	return 0;
}