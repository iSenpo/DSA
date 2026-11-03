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
    int ans = 0;
    int temp;
    int i = 0;
    while(i < n){
        if(a[i] == 1){
            ans++;
            i++;
            continue;
        }
        int pr = i + 1;
        bool block = true;
        int k = a[i];
        while(--k){
            if(a[pr++] != a[i]){
                block = false;
                break;
            }
        }
        if(block && k == 0){
            ans += a[i];
        }
        else{
            pr--;
        }
        i = pr;
    }
    cout << ans << ln;
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