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

void solve()
{
    int n , s , d;
    cin >> n >> s >> d;
    pii base = {0 , 0};
    int cnt = 0;
    map<int , pii> a;
    bool first = true;
    int i = 1 , j = 1;
    for(i ; i <= n ; i++){
        cnt++;
        a[cnt] = {base.first + i , j};
        cerr << cnt << " : " << a[cnt].first << ' ' << a[cnt].second << ln;
    }
    int t = n;
    int k = 0;
    while(cnt < n*n){
        if(k % 2 == 0 || k == 0)
            t--;
        for(j ; j <= t ; j++){
            cnt++;
            a[cnt] = {base.first + i , base.second + j};
            cerr << cnt << " : " << a[cnt].first << ' ' << a[cnt].second << ln;
        }
        k++;
        if(k % 2 == 0)
            t--;
        for(i ; i >= t ; i--){
            cnt++;
            a[cnt] = {base.first + i , base.second + j};
            cerr << cnt << " : " << a[cnt].first << ' ' << a[cnt].second << ln;
        }
        k++;
        if(k % 2 == 0)
            t--;
        for(j ; j >= t ; j--){
            cnt++;
            a[cnt] = {base.first + i , base.second + j};
            cerr << cnt << " : " << a[cnt].first << ' ' << a[cnt].second << ln;
        }
        k++;
        base.first++;
        base.second++;
        if(k % 2 == 0)
            t--;
        for(i ; i <= t ; i++){
            cnt++;
            a[cnt] = {base.first + i , base.second + j};
            cerr << cnt << " : " << a[cnt].first << ' ' << a[cnt].second << ln;
        }
    }
    int dx = a[d].first - a[s].first;
    int dy = a[d].second - a[s].second;
    if(dx < 0){
        cout << abs(dx) << ' ' << 'L' << ln;
    }
    else{
        cout << dx << " R\n";
    }
    if(dy < 0){
        cout << abs(dy) << " D\n";
    }
    else{
        cout << dy << " U\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
//check long long memory limit
//check int overflow