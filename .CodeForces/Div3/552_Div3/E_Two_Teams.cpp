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
bool mark[N];
int pr[N] , pl[N];
int n;
int findl(int v){
    if(v < 0){
        return -1;
    }
    if(v == pl[v]){
        return v;
    }
    return pl[v] = findl(pl[v]); 
}
int findr(int v){
    if(v >= n){
        return n;
    }
    if(v == pr[v]){
        return v;
    }
    return pr[v] = findr(pr[v]);
}
void solve()
{
    int k;
    cin >> n >> k;
    int a[n];
    vector<pii> v(n);
    fo(i , n){
        cin >> a[i];
        v[i] = {a[i] , i};
        pr[i] = i;
        pl[i] = i;
    } 
    sort(all(v));
    reverse(all(v));
    int ans[n];
    int team = 0;
    for(int i = 0 ; i < n ; i++){
        int ind = v[i].second;
        if(mark[ind]){
            continue;
        }
        mark[ind] = true;
        a[ind] = team;
        pr[ind] = findr(ind + 1);
        pl[ind] = findl(ind - 1);
        int r = findr(ind + 1) , l = findl(ind - 1);
        int tr = k , tl = k;
        while(tr-- && r < n){
            mark[r] = true;
            a[r] = team;
            pr[r] = findr(r + 1);
            pl[r] = findl(r - 1);
            r = findr(r + 1);
        }
        while(tl-- && l >= 0){
            mark[l] = true;
            a[l] = team;
            pl[l] = findl(l - 1);
            pr[l] = findr(l + 1);
            l = findl(l - 1);
        }
        team = 1 - team;
    }
    for(int i = 0 ; i < n ; i++){
        cout << a[i] + 1 ;
    }
    cout << ln;
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