#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int , int>
#define ln '\n'

const int N = 2e5 + 500;
int par[N] , rnk[N];

int find(int v){
    if(par[v] == -1){
        return v;
    }
    return par[v] = find(par[v]);
}
void merge(int v , int u){
    v = find(v);
    u = find(u);
    if(v == u) return ;
    if(rnk[v] >= rnk[u]){
        par[u] = v;
        rnk[v] = max(rnk[v] , rnk[u] + 1);
    }
    else{
        par[v] = u;
        rnk[u] = max(rnk[u] , rnk[v] + 1);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int n , q;
    cin >> n >> q;
    memset(par , -1 , sizeof par);
    memset(rnk , 0 , sizeof rnk);
    while(q--){
        char ch;
        int x , y;
        cin >> ch;
        if(ch == '?'){
            cin >> x >> y;
            if(find(x) == find(y)){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
        else{
            cin >> x >> y;
            merge(x , y);
            cout << "merged!" << ln;
        }
    }
    return 0;
}
