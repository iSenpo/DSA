#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; i++)
#define all(x) (x).begin(),(x).end()
int MOD = 998244353;
const int N  = 1e5 + 500;
int arr[N];

inline int in(){
    int x;
    cin >> x;
    return x;
}
void solve()
{
    int n = in();
    int a[n] , b[n];
    fo(i , n) cin >> a[i];
    fo(i , n) cin >> b[i];
    long long ans = 0;
    fo(i , n){
        if(b[i] <= a[i]){
            ans++;
        }
    }
    long long res = 1;
    fo(i , ans){
        res = (res * 2)%MOD;
    }
    cout << res << ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = in();
    while(t--){
        solve();
    }
    return 0;
}