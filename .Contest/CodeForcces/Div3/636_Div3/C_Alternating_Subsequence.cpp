#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int , int>
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; ++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb(x) push_back(x)
#define mt(x , y , z) make_tuple(x , y , z)

// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z

const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int MOD = 1e9 + 7;

const int N  = 2e5 + 10;
//always check input!!!
const int MIN = -2e9;
const int MAX = 2e9;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    fo(i , n) cin >> a[i];
    ll Maxp = MIN;
    ll Minn = MIN;
    ll sum1 = 0;
    int cnt1 = 0;
    for(int i = 0 ; i < n ;i = i){
        while(i < n && a[i] > 0){
            Maxp = max(a[i] , Maxp);
            i++;
        }
        if(Maxp == MIN){
            break;
        }
        while(i < n && a[i] < 0){
            Minn = max(Minn , a[i]);
            i++;
        }
        if(Minn != MIN){
            sum1 += Maxp + Minn;
            cnt1 += 2;
        }
        else if(Maxp != MIN){
            sum1 += Maxp;
            cnt1++;
            break;
        }
        else{
            break;
        }
        Minn = MIN;
        Maxp = MIN;
    }
    Maxp = MIN;
    Minn = MIN;
    ll sum2 = 0;
    int cnt2 = 0;
    for(int i = 0 ; i < n ;i = i){
        while(i < n && a[i] < 0){
            Minn = max(Minn , a[i]);
            i++;
        }
        if(Minn == MIN){
            break;
        }
        while(i < n && a[i] > 0){
            Maxp = max(a[i] , Maxp);
            i++;
        }
        if(Maxp != MIN){
            sum2 += Maxp + Minn;
            cnt2 += 2;
        }
        else if(Minn != MIN){
            sum2 += Minn;
            cnt2++;
            break;
        }
        else{
            break;
        }
        Minn = MIN;
        Maxp = MIN;
    }
    if(cnt1 > cnt2){
        cout << sum1 << ln;
    }
    else if(cnt1 == cnt2){
        cout << max(sum1 , sum2) << ln;
    }
    else{
        cout << sum2 << ln;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
//check long long memory limit
//check int overflow