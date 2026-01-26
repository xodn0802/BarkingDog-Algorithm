#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[1002];
int fire_dist[1002][1002];
int sg_dist[1002][1002];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int t,w,h;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> w >> h;
        for(int i = 0; i < h; i++){
            cin >> board[i];
            fill(fire_dist[i],fire_dist[i] + w, -1);
            fill(sg_dist[i],sg_dist[i]+w,-1);
        }
        queue<pair<int,int>> FQ;
        queue<pair<int,int>> SQ;
        bool escape = false;

        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(board[i][j] == '*'){
                    fire_dist[i][j] = 0;
                    FQ.push({i,j});
                }
                else if(board[i][j] == '@'){
                    sg_dist[i][j] = 0;
                    SQ.push({i,j});
                }
            }
        }
        while(!FQ.empty()){
            auto cur = FQ.front(); FQ.pop();
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if(board[nx][ny] == '#') continue;
                if(fire_dist[nx][ny] >= 0) continue;
                fire_dist[nx][ny] = fire_dist[cur.X][cur.Y] + 1;
                FQ.push({nx,ny});
            }
        }
        while(!SQ.empty()){
            auto cur = SQ.front(); SQ.pop();
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w){
                    escape = true;
                    cout << sg_dist[cur.X][cur.Y] + 1 << '\n';
                    break;
                }
                if(board[nx][ny] == '#') continue;
                if(sg_dist[nx][ny] >= 0) continue;
                if(fire_dist[nx][ny] != -1 && fire_dist[nx][ny] <= sg_dist[cur.X][cur.Y] + 1) continue;
                sg_dist[nx][ny] = sg_dist[cur.X][cur.Y] + 1;
                SQ.push({nx,ny});
            }
            if(escape) break;
        }
        if(escape == false){
            cout << "IMPOSSIBLE\n";
        }
    }

    return 0;
}