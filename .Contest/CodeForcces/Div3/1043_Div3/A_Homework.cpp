#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; i++)
int MOD = 1e9 + 7;
const int N  = 1e5 + 500;
int arr[N];

void solve()
{
    int n , m;
    string a , b , o;
    cin >> n >> a >> m >> b >> o;
    for(int i = 0 ; i < m ; i++){
        if(o[i] == 'D'){
            a = a + b[i];
        }
        else{
            a = b[i] + a;
        }
    }
    cout << a << ln;
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