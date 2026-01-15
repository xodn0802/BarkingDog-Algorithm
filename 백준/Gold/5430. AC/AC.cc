#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n;
    string p,x;

    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> p >> n >> x;
        deque<int> DQ;
        if(n != 0){
            int cur = 0;
            for(int j = 1; j < x.size() - 1; j++){
                if(x[j] == ','){
                    DQ.push_back(cur);
                    cur = 0;
                }else{
                    cur = 10 * cur + (x[j] - '0');
                }
            }
            DQ.push_back(cur);
        }

        bool dir = true;
        bool isError = false;
        for(int j = 0; j < p.size(); j++){
            if(p[j] == 'R'){
                dir = !dir;
            }else if(p[j] == 'D'){
                if(DQ.empty()){
                    isError = true;
                }
                if(dir){
                    DQ.pop_front();
                }else{
                    DQ.pop_back();
                }
            }
        }
        if(isError){
            cout << "error\n";
        }else{
            cout << "[";
            if(dir){
                for(int j = 0; j < DQ.size(); j++){
                    cout << DQ[j];
                    if(j != DQ.size() - 1) cout << ",";
                }
            }else{
                for(int j = DQ.size() - 1; j >= 0; j--){
                    cout << DQ[j];
                    if(j != 0) cout << ",";
                }
            }
            cout << "]\n";
        }
        
    }

    return 0;
}