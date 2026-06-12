#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int , int>
#define pll pair<ll , ll>
#define ln '\n'
#define lid id*2
#define rid id*2 + 1
#define mid (l + r)/2


// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int MOD = 1e9 + 7;
const int N  = 2e5 + 10;
const int INF = 2e9 + 100;
const int MIN = -2e9 - 100;
//always check input!!!


struct tree{
    ll ans , pre , suf , sum;
    tree(ll _ans , ll _pre , ll _suf , ll _sum):ans(_ans) , pre(_pre) , suf(_suf) , sum(_sum){}
    tree(){}
    
};
tree merge(tree x , tree y){
    return tree(
        max({x.ans , y.ans , x.suf + y.pre}) ,
        max(x.pre , x.sum + y.pre) ,
        max(y.suf , y.sum + x.suf) , 
        (x.sum + y.sum)
    );
}
int n , q ;
ll a[N];
tree seg[N * 4];

void build(int l = 0 , int r = n , int id = 1){
    if(l + 1 == r){
        seg[id] = tree(max(a[l] , 0LL) , max(a[l] , 0LL) , max(a[l] , 0LL) , a[l]);
        return;
    }
    build(l , mid , id * 2);
    build(mid , r , id * 2 + 1);
    //something
    seg[id] = merge(seg[lid] , seg[rid]);
}
void update(int p , int x , int l = 0, int r = n , int id = 1){
    if(l + 1 == r){
        seg[id] = tree(max(a[l] , 0LL) , max(a[l] , 0LL) , max(a[l] , 0LL) , a[l]);
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
    return merge(get(s , e, l , mid , lid) , get(s , e , mid , r , rid));
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> q;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    build();
    return 0;
}
