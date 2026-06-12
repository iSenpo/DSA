#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'

const int N  = 1e5 + 500;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int n ; 
    cin >> n;
    int a[n + 1];
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i] ;
    }
    for(int i = 1 ; i <= n ; i++){
        if(a[a[a[i]]] == i){
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}