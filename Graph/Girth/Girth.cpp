#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'

const int N = 1e3;
int ans = N;
bool seen[N];
vector<int> adj[N];
int h[N];
int par[N];

void input(){
   /*
    1--\ /---4
    |   3    |
    2--/ \---5
    */
   adj[0] = {0};
   adj[1] = {2 , 3};
   adj[2] = {1 , 3};
   adj[3] = {1 , 2 , 4 , 5};
   adj[4] = {3 , 5};
   adj[5] = {3 , 4};
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    input();
    for(int n = 1 ; n <= 5 ; n++){
        memset(seen , false , sizeof seen);
        memset(h , 63 , sizeof h);
        memset(par , -1 , sizeof par);

        vector<int> node;
        node.push_back(n);
        seen[n] = true;
        h[n] = 0;
        par[n] = 0;

        for(int i = 0 ; i < node.size() ; i++){
            int v = node[i];
            for(int u : adj[v]){
                if(!seen[u]){
                    node.push_back(u);
                    seen[u] = true;
                    h[u] = h[v] + 1;
                    par[u] = v;
                }
                else if(u != par[v]){
                    ans = min(ans , h[u] + h[v] + 1);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}