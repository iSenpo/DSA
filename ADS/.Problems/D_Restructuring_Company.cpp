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
int par[N] , rnk[N];
int par2[N] , rnk2[N];

int find(int v){
    if(par[v] == -1){
        return v;
    }
    par[v] = find(par[v]);
    return par[v];
}
void merge(int v , int u){
    v = find(v);
    u = find(u);
    if(v == u) return;
    if(rnk[v] >= rnk[u]){
        par[u] = v;
        rnk[v] = max(rnk[v] , rnk[u] + 1);
    }
    else{
        par[v] = u;
        rnk[u] = max(rnk[u] , rnk[v] + 1);
    }
}
int find2(int v){
    if(par2[v] == -1){
        return v;
    }
    par2[v] = find2(par2[v]);
    return par2[v];
}
void merge2(int v , int u){
    v = find2(v);
    u = find2(u);
    if(v == u) return;
    if(rnk2[v] >= rnk2[u]){
        par2[u] = v;
        rnk2[v] = max(rnk2[v] , rnk2[u] + 1);
    }
    else{
        par2[v] = u;
        rnk2[u] = max(rnk2[u] , rnk2[v] + 1);
    }
}
void solve()
{
    int n , q;
    cin >> n >> q;
    memset(par , - 1 , sizeof par);
    memset(par2 , -1 , sizeof par2);
    while(q--){
        int a , b , c;
        cin >> a >> b >> c;
        if(a == 1){
            merge(b , c);
        }
        if(a == 2){
            while(b <= c){
                int root = find2(b);
                if(root > c) 
                    break; 
                int low = root, high = c ,ans = root;
                while(low <= high){
                    int mid = (low + high) / 2;
                    if(find2(mid) == root){
                        ans = mid;
                        low = mid + 1;
                    }
                    else{
                        high = mid - 1;
                    }
                }
                if(ans == c)
                    break;
                merge(root, ans + 1);
                merge2(root, ans + 1);
                b = ans + 1;
            }
        }
        if(a == 3){
            if(find(b) == find(c)){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
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