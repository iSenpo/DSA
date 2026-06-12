#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int , int>
#define pll pair<ll , ll>
#define ln '\n'

const int N = 2e5 + 500;
int n , q , node[N * 2];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> q;
    for(int i = 0 ; i < n ; i++){
        cin >> node[i + n];
    }    
    for(int i = n - 1 ; i > 0 ; i--){
        node[i] = node[i * 2] + node[i * 2 + 1];
    }
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int p , x;
            cin >> p >> x;
            p += n;
            node[p] = x;
            p /= 2;
            while(p > 0){
                node[p] = node[p * 2] + node[p * 2 + 1];
                p /= 2;
            }
        }
        else if(type == 2){
            int l , r;
            cin >> l >> r;
            l += n;
            r += n;
            int ans = 0;
            while(l < r){
                if(l % 2 == 1){
                    ans += node[l++];
                }
                if(r % 2 == 1){
                    ans += node[--r];
                }
                l /= 2;
                r /= 2;
            }
            cout << ans << ln;
        }
    }
    return 0;
}
