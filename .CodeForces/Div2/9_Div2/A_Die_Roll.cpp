#include <bits/stdc++.h>
using namespace std;


void solve()
{
    int n , m;
    cin >> n >> m;
    int t = max(n , m);
    if(t == 1){
        cout << "1/1";
    }
    else if(t == 2){
        cout << "5/6";
    }
    else if(t == 3){
        cout << "2/3";
    }
    else if(t == 4){
        cout << "1/2";
    }
    else if(t == 5){
        cout << "1/3";
    }
    else{
        cout << "1/6";
    }
}
int main(){
    solve();
    return 0;
}
