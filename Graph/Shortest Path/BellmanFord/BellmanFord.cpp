#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int , int>
#define ln '\n'

const int N = 1e5 + 10;
const int INF = 1e9;
int v[N] , u[N] , w[N] , d[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int n , m , source;
    cin >> n >> m;
    source = 0;
    for(int i = 0 ; i < m ; ++i){
        int V , U , W;
        cin >> V >> U >> W;
        V--;
        U--;
        v[i] = V;
        u[i] = U;
        w[i] = W;
    }    
    fill(d, d + N, INF);
    d[source] = 0;
    for(int i = 0 ; i < n ; ++i){
        bool check = true;
        for(int j = 0 ; j < m ; ++j){
            if(d[v[j]] + w[j] < d[u[j]]){
                check = false;
                d[u[j]] = d[v[j]] + w[j];
            }
        }
        if(check)   break;
    }
    for(int i = 0 ; i < n ; ++i){
        cout << i + 1 << " : " << d[i] << ln;
    }
    return 0;
}
//check long long memory limit
//check int overflow