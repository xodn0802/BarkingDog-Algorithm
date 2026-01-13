#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x){
    dat[pos] = x;
    pos++;
}

bool empty(){
    if(pos == 0){
        return true;
    }return false;
}

int pop(){
    if(empty()) return -1;
    pos--;
    return dat[pos];
}

int size(){
    return pos;
}



int top(){
    if(empty()) return -1;
    return dat[pos-1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    string s;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> s;
        if(s == "push"){
            cin >> m;
            push(m);
        }else if(s == "pop"){
            cout << pop() << '\n';
        }else if(s == "size"){
            cout << size() << '\n';
        }else if(s == "empty"){
            if(empty()) cout << 1 << '\n';
            else{
                cout << 0 << '\n';
            }
        }else{
            cout << top() << '\n';
        }
    }
    return 0;
}