#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; i++)
#define all(x) (x).begin(),(x).end()
int MOD = 1e9 + 7;
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
    int a[n];
    fo(i , n) cin >> a[i];
    int cnt0 = 0;
    int cnt1 = 0;
    fo(i , n){
        if(a[i] == 0){
            cnt0++;
        }
        if(a[i] == -1){
            cnt1++;
        }
    }
    int ans = 0;
    ans += cnt0;
    if(cnt1 == 0){
    }
    else{
        if(cnt1%2 == 1){
            ans += 2;
        }
    }
    cout << ans << ln;
    return;
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