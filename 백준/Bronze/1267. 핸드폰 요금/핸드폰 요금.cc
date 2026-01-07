#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num, time;
    int y_cnt = 0;
    int m_cnt = 0;
    cin >> num;
    //int arr[num];
    for(int i = 0; i < num; i++){
        cin >> time;
        //arr[i] = time;
        y_cnt += ((time / 30) + 1) * 10;
        m_cnt += ((time / 60) + 1) * 15;
    }
    if(y_cnt < m_cnt){
        cout << "Y " << y_cnt;
    }else if(y_cnt > m_cnt){
        cout << "M " << m_cnt;
    }else{
        cout << "Y M " << m_cnt;
    }
    

    return 0;
}