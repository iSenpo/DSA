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
   int n , a , b , k;
   cin >> n >> a >> b >> k;
   int ar[n];
   map<int , int> r;
   ll ans = 0;
   int d = (a + b);
   set<int> R;
   fo(i , n){
        cin >> ar[i];
        if(ar[i] <= a){
            ans++;
            continue;
        }
        if(ar[i]%d <= a && ar[i]%d != 0 && ar[i] > d){
            ans++;
            continue;
        }
        int l = (ar[i] / d);
        if(ar[i]%d == 0){
            l--;
        }
        ar[i] -= (l * d + a);
        R.insert(ar[i]);
        r[ar[i]]++;
    }
   vector<int> t(all(R));
   for(int i : t){
        while(r[i] > 0){
            int hp = i;
            int p = hp/a;
            if(p <= k){
                hp -= (p * a);
                k -= p;
            }
            while(hp > 0 && k > 0){
                hp -= a;
                k--;
            }
            if(hp <= 0){
                ans++;
            }
            else{
                break;
            }
            r[i]--;
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