#include <bits/stdc++.h>
using namespace std;
#define ll long long
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

const int N  = 1e5 + 500;

inline int in(){
    int x;
    cin >> x;
    return x;
}

void solve()
{
    int n = in();
    int a[n];
    fo(i , n) cin >> a[i];
    sort(a , a + n);
    vector<int> ans(3);
    fo(i , n){
        fo(j , 31){
            int l = a[i] - (1 << j);
            int r = a[i] + (1 << j);
            bool left = binary_search(a , a + n , l);
            bool right = binary_search(a , a + n , r);
            if(left && right){
                cout << 3 << ln;
                cout << (int)l << ' ' << (int)a[i] << ' ' << (int)r << ln;
                return;
            }
            if(left){
                ans = {l , a[i]};
            }
            if(right){
                ans = {a[i] , r};
            }
        }
    }
    if(sz(ans) == 2){
        cout << 2 << ln;
        cout << (int)ans[0] << ' ' << (int)ans[1] << ln;
        return;
    }
    fo(i , 31){
        if(binary_search(a , a + n , (1 << i))){
            cout << 1 << ln << (int)(1 << i) << ln;
            return;
        }
    }
    cout << 1 << ln << a[0] << ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = 1;
    //t = in();
    while(t--){
        solve();
    }
    return 0;
}