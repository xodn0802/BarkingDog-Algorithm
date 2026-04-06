#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int note[42][42];
int K;
int r, c;
int paper[12][12];
int N, M;

bool portable(int x, int y) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (note[x + i][y + j] == 1 && paper[i][j] == 1) {
				return false;
			}
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (paper[i][j] == 1) {
				note[x + i][y + j] = 1;
			}
		}
	}
	return true;
}

void rotate() {
	int temp[12][12];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			temp[i][j] = paper[i][j];
		}
	}
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			paper[i][j] = temp[r - 1 - j][i];
		}
	}
	swap(r, c);
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);

	cin >> N >> M >> K;
	while (K--) {
		cin >> r >> c;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> paper[i][j];
			}
		}
		for (int i = 0; i < 4; i++) {
			bool isPaste = false;
			for (int j = 0; j <= N-r; j++) {
				if (isPaste) break;
				for (int z = 0; z <= M-c; z++) {
					if (portable(j, z)) {
						isPaste = true;
						break;
					}
				}
			}
			if (isPaste) break;
			rotate();
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (note[i][j] == 1) cnt++;
		}
	}
	cout << cnt;

	
	return 0;
}