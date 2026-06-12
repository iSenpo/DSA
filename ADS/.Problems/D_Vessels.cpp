#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int , int>
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; ++i)

const int N  = 1e5 + 10;

vector<int> a , par , cnt;
int n;
int find(int v){
    if(v < 0){
        return 0;
    }
    if(v > n + 5){
        return 0;
    }
    if(par[v] == -1){
        return v;
    }
    return par[v] = find(par[v]);
}
void fill(int v ,int x){
    if(v > n){
        return;
    }
    if(cnt[v] + x > a[v]){
        par[v] = v + 1;
        int t = cnt[v] + x - a[v];
        cnt[v] = a[v];
        fill(v + 1 , t);
    }
    else{
        cnt[v] += x;
    }
}
void solve()
{
    cin >> n;
    a.resize(n + N);
    par.resize(N + n , -1);
    cnt.resize(N + n , 0);
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
    int q;
    cin >> q;
    while(q--){
        int a;
        cin >> a;
        if(a == 1){
            int p , litr;
            cin >> p >> litr;
            fill(find(p) , litr);
        }
        else{
            int x;
            cin >> x;
            cout << cnt[x] << ln;
        }
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