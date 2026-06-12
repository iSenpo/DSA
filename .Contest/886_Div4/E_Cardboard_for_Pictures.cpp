#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  = 1e5 + 500;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n , c;
        cin >> n >> c;
        ll a[n];
        for(ll i = 0 ; i < n ; i++){
            cin >> a[i];
        }
        for(ll i = 0 ; i < n ; i++){
            c -= a[i]*a[i];
        }
        int b = 0;
        for(ll i = 0 ; i < n ; i++){
            b += a[i];
        }
        c -= 2*c;
        int delta = 4 * n * c;
        int ans = (-b + sqrt(b*b - delta))/2*n;
        cout << ans << endl;
    }
    return 0;
}