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
    int n , k;
    cin >> n >> k;
    int d = (k * 2) - n;
    int ac = k , bc = k;
    vector<int> mo , aa , bb , rev;
    fo(i , n){
        int t , a , b;
        cin >> t >> a >> b;
        if(a == 1 && b == 1){
            mo.push_back(t);
        }
        else if(a == 1){
            aa.push_back(t);
        }
        else if(b == 1){
            bb.push_back(t);
        }
    }
    sort(all(mo));
    reverse(all(mo));
    sort(all(aa));
    reverse(all(aa));
    sort(all(bb));
    reverse(all(bb));
    ll ans = 0;
    int szm = sz(mo);
    fo(i , min(szm , k)){
        ans += mo.back();
        rev.push_back(mo.back());
        mo.pop_back();
        ac--;
        bc--;
    }
    if((int)ac > ((int)aa.size()) || (int)bc > (int)bb.size()){
        cout << -1 << ln;
        return;
    }
    while(ac > 0){
        ans += aa.back();
        aa.pop_back();
        ac--;
    }
    while(bc > 0){
        ans += bb.back();
        bb.pop_back();
        bc--;
    }
    while((int)aa.size() > 0 && (int)bb.size() > 0 && (int)rev.size() > 0){
        int x = aa.back();
        int y = bb.back();
        int m = rev.back();
        if(x + y < m){
            ans -= m;
            ans += x + y;
            aa.pop_back();
            bb.pop_back();
            mo.pop_back();
        }
        else{
            break;
        }
    }
    cout << ans << ln;
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