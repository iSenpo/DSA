#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int , int>
#define pll pair<ll , ll>
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; ++i)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) (int)(x).size()
#define pb(x) push_back(x)
#define	set_dec(x) cout << fixed << setprecision(x);
// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int MOD = 1e9 + 7;
const int N  = 2e5 + 10;
const int INF = 2e9 + 100;
const int MIN = -2e9 - 100;
//always check input!!!


bool isPow2(ll a){
    ll j = 1;
    fo(i , 30){
        if((j << i) == a){
            return true;
        } 
    }
    return false;
}
void solve()
{
    int n;
    cin >> n;
    int a[n];
    if(n <= 3){
        for(int i = 1; i <= 3; i++){
            cout << i << ' ';
        }
        cout << ln;
        return;
    }
    fo(i , n) a[i] = (i + 1);
    if(n % 2 == 1){
        for(int i = 1 ; i < n - 1; i++){
            if((a[i] | 1) == a[n - 1]){
                swap(a[i] , a[n - 2]);
                break;
            }
        }
    }
    else{
        if(isPow2(n)){
            swap(a[n - 1] , a[2]);
            swap(a[2] , a[1]);
        }
        else{
            int ind1 , ind2;
            bool x = 0;
            int v1 , v2;
            ll temp = a[n - 1];
            for(int i = 30 ; i >=0 ; i--){
                ll j = (1 << i);
                if(temp - j >= 0){
                    temp -= j;
                    v1 = j;
                    break;
                }
            }
            for(int i = 30 ; i >= 0 ; i--){
                ll j = (1 << i);
                if(temp - j >= 0){
                    v2 = j;
                    break;
                }
            }
            fo(i , n - 1){
                if(a[i] == v1){
                    ind1 = i;
                }
            }
            fo(i , n - 2){
                if(a[i] == v2){
                    ind2 = i;
                }
            }
            swap(a[0] , a[ind1]);
            swap(a[n - 2] , a[ind2]);
        }
    }
    fo(i , n) cout << a[i] << ' ';
    cout << ln; 
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
