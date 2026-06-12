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
    int ps[n];
    cin >> a[0];
    ps[0] = a[0];
    for(int i = 1 ; i < n ; i++){
        cin >> a[i];
        ps[i] = a[i] + ps[i-1];
    }
    for(int i = 0; i < n - 2 ; i++){
        int l = ps[i]%3; 
        for(int j = i + 1 ; j < n - 1 ; j++){
            int m = (ps[j] - ps[i]) % 3;
            int r = (ps[n-1] - ps[j]) % 3;
            if(l == m && m == r){
                cout << i + 1 << ' ' << j + 1 << ln;
                return;
            }
            if(l != m && l != r && r != m){
                cout << i + 1 << ' ' << j + 1 << ln;
                return;
            }
        }
    }
    cout << 0 << ' ' << 0 << ln;
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