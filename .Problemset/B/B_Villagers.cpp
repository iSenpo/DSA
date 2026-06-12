#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    sort(a , a + n);
    ll Sum = 0;
    for(int i = n -1 ; i >= 1 ; i--){
        int u = max(a[i] , a[i-1]);
        int v = min(a[i] , a[i-1]);
        Sum += u;
        i--;
    }
    if(n%2 == 1){
        Sum += a[0];
    }
    cout << Sum << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}