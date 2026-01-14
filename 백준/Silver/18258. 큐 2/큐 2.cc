#include <bits/stdc++.h>
using namespace std;

const int MX = 2000005;
int dat[MX];
int head = 0, tail = 0;

void push(int x){
    dat[tail] = x;
    tail++;
}

void pop(){
    head++;
}

int front(){
    return dat[head];
}

int back(){
    return dat[tail-1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    string s;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        if(s == "push"){
            cin >> k;
            push(k);
        }else if(s == "pop"){
            if(head == tail){
                cout << -1 << '\n';
            }else{
                cout << front() << '\n';
                pop();
            }
        }else if(s == "size"){
            cout << tail - head << '\n';
        }else if(s == "empty"){
            if(head == tail){
                cout << 1 << '\n';
            }else{
                cout << 0 << '\n';
            }
        }else if(s == "front"){
            if(head == tail){
                cout << -1 << "\n";
            }else{
                cout << front() << '\n';
            }
        }else{
            if(head == tail){
                cout << -1 << '\n';
            }else{
                cout << back() << '\n';
            }
        }
    }


    return 0;
}