#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int , int>
#define pll pair<ll , ll>
#define ln '\n'

const int N = 2e5 + 10;
int n , q , node[4 * N] , a[N];

void build(int l = 0 , int r = n , int id = 1){
    if(l + 1 == r){
        node[id] = a[l]; // ----> *a[l]
        return;
    }
    int mid = (l + r)/2;
    build(l , mid , id * 2);
    build(mid , r , id * 2 + 1);
    node[id] = max(node[id * 2] , node[id * 2 + 1]);
}
int get(int s, int e , int l = 0 , int r = n , int id = 1){
    if(s <= l && r <= e){
        return node[id];
    }
    if(e <= l || r <= s){
        return 0;
    }
    int mid = (l + r) / 2;
    return max(get(s , e , l , mid , id * 2) , get(s , e , mid , r , id * 2 + 1));
}
void update(int p , int x , int l = 0 , int r = n , int id = 1){
    if(l + 1 == r){
        node[id] = x;
        return;
    }
    int mid = (l + r) / 2;
    if(p < mid){
        update(p , x , l , mid , id * 2);
    }
    else{
        update(p , x , mid , r , id * 2 + 1);
    }
    node[id] = max(node[id * 2] , node[id * 2 + 1]);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> q;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    build();
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int p , x;
            cin >> p >> x;
            update(p , x);
        }
        if(type == 2){
            int l , r;
            cin >> l >> r;
            cout << get(l , r) << ln;
        }
    }
    return 0;
}
