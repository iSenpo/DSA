#include <bits/stdc++.h>
using namespace std;
#define ll long long
int MOD = 1e9 + 7;
const int N  = 1e5 + 500;
int a[N];

void solve()
{

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*-------------------------------------*/
    int n , k;
    cin >> n >> k;
    vector<ll> postive(n + 1 , 0);
    vector<ll> ps(n + 1 , 0);

    for(int i = 0 ; i < n ; i++){
        cin >> a[i] ;
        postive[i + 1] = postive[i] + max(0 , a[i]);
        ps[i + 1] = ps[i] + a[i];
    }
    ll ans = 0;
    for(int i = 0 ; i + k <= n ; i++){
        ll left = postive[i];
        ll right = postive[n] - postive[i + k];
        ll mid = ps[i + k] - ps[i];
        if(mid < 0){
            mid = 0;
        }
        ans = max(ans , mid + right + left);
    }
    cout << ans;
    return 0;
}