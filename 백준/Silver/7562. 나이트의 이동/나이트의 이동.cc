#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

//int board[304][304];
int dist[304][304];
int dx[8] = {-2,-2,-1,1,2,2,1,-1};
int dy[8] = {-1,1,2,2,1,-1,-2,-2};
int t,l,n,m;
int p,o;
int ansx,ansy;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> l;
        for(int j = 0; j < l; j++){
            //fill(board[j], board[j]+l,0);
            fill(dist[j],dist[j]+l,-1);
        }
        cin >> n >> m;
        cin >> o >> p;
        dist[n][m] = 0;
        queue<pair<int,int>> Q;
        Q.push({n,m});
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            for(int dir = 0; dir < 8; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx == o && ny == p){
                    ansx = nx;
                    ansy = ny;
                }
                if(nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
                if(dist[nx][ny] >= 0) continue;
                Q.push({nx,ny});
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            }
        }
        cout << dist[ansx][ansy] << '\n';

    }

    return 0;
}