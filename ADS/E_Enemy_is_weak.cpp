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
#define lid (id * 2)
#define rid ((id * 2) + 1)
#define mid ((l + r) / 2)
int a[N] , b[N] , c[N] , d[N];
int n;
struct tree{
    ll sum = 0;
    tree(ll sum_):sum(sum_){}
    tree(){}
};
tree seg[N << 2];
tree merge(tree x , tree y){
    return tree(x.sum + y.sum);
}
void build(int l = 0 , int r = n , int id = 1){
    if((l + 1) == r){
        seg[id].sum = 0;
        return;
    }
    build(l , mid , lid);
    build(mid , r , rid);
    seg[id] = merge(seg[lid] , seg[rid]);
}
tree get(int s , int e , int l = 0 , int r = n , int id = 1){
    if(s <= l && r <= e){
        return seg[id];
    }
    if(e <= mid){
        return get(s , e , l , mid , lid);
    }
    if(s >= mid){
        return get(s , e , mid , r , rid);
    }
    return merge(get(s , e , l , mid , lid) , get(s , e , mid , r , rid));
}
void update(int p , int x , int l = 0 , int r = n , int id = 1){
    if((l + 1) == r){
        seg[id].sum += x;
        return;
    }
    if(p < mid){
        update(p , x , l , mid , lid);
    }
    else{
        update(p , x , mid , r , rid);
    }
    seg[id] = merge(seg[lid] , seg[rid]);
}
void solve()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    
    memcpy(b , a , sizeof(a));
    sort(b , b + n);

    int m = unique(b , b + n) - b;

    for(int j = 0 ; j < n ; j++){
        int id = upper_bound(b , b + n , a[j]) - b;
        c[j] = get(id , n).sum;
        update(id - 1 , 1);
    }
    for(int j = N - 1 ; ~j ; j--){
        int id = lower_bound(b , b + n , a[j]) - b;
        d[j] = get(0 , id).sum;
        update(id , 1);
    }
    ll ans = 0;
    for(int i = 0 ; i < n ; i++){
        ans += (c[i] * (1LL) * b[i]);
    }
    cout << ans << ln;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
