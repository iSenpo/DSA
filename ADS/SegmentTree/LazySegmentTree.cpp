#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int , int>
#define pll pair<ll , ll>
#define ln '\n'
#define lid (id * 2)
#define rid ((id * 2) + 1)
#define mid ((r + l) / 2)
const int N = 1e6 + 100;
//data
//merge
//lazy
//relax
int n;
int a[N];
struct tree{
    ll sum;
    tree(ll sum_): sum(sum_){}
    tree(){}
};
tree seg[N * 4];
tree merge(tree x , tree y){
    return tree(x.sum + y.sum);
}
struct lazy{
    bool flag = false;
    ll add = 0;
    lazy(ll add_): add(add_){}
    lazy(){}
    void set(ll x){
        add += x;
        flag = true;
    }
    void reset(){
        add = 0;
        flag = false;
    }
};
lazy seg_lazy[N * 4];
void relax(int l , int r , int id){
    if(!seg_lazy[id].flag || l + 1 == r) return;

    ll x = seg_lazy[id].add;

    seg[lid].sum += (x * (mid - l));
    seg[rid].sum += (x * (r - mid));

    seg_lazy[lid].set(x);
    seg_lazy[rid].set(x);

    seg_lazy[id].reset();
}
void build(int l = 0 , int r = n , int id = 1){
    if((l + 1) == r){
        seg[id] = tree(a[l]);
        return;
    }
    build(l , mid , id * 2);
    build(mid , r , id * 2 + 1);

    seg[id] = merge(seg[lid] , seg[rid]);
}
tree get(int s , int e , int l = 0 , int r = n , int id = 1){
    if(e <= l || r <= s)
        return tree(0);

    if(s <= l && r <= e)
        return seg[id];

    relax(l , r , id);

    if(e <= mid)
        return get(s , e , l , mid , lid);
    if(s >= mid)
        return get(s , e , mid , r , rid);
        
    return merge(get(s , e, l , mid , lid) , get(s , e , mid , r , rid));
}

void update(int s , int e , int x , int l = 0 , int r = n , int id = 1){
    if(e <= l || r <= s) return;

    if(s <= l && r <= e){
        seg[id].sum += (1LL) * x * (r - l);
        seg_lazy[id].set(x);
        return;
    }

    if(seg_lazy[id].flag)
        relax(l , r , id);

    update(s , e , x , l , mid , lid);
    update(s , e , x , mid , r , rid);

    seg[id] = merge(seg[lid] , seg[rid]);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int q;
    cin >> n >> q;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];

    build();
    while(q--){
        int tp;
        cin >> tp;
        if(tp == 2){
            int p;
            cin >> p;
            cout << get(p - 1 , p).sum << ln;
        }
        if(tp == 1){
            int l , r , x;
            cin >> l >> r >> x;
            update(l - 1 , r , x);
        }
    }
    return 0;
}
