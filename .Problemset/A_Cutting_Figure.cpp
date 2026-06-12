#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false) , cin.tie(NULL) , cout.tie(NULL);
#define ll long long
#define pii pair<int , int>
#define ln '\n'

const int N  = 55;
int n , m;
vector<pii> adj[N][N];
bool mark[N][N];
int h[N][N] , up[N][N];
char s[N][N];
vector<pii> ans;

const int dx[4] = {-1 , 0 , 1 , 0};
const int dy[4] = {0 , -1 , 0 , 1};

void dfs(int i , int j , int ip = -1 , int jp = -1){
    mark[i][j] = true;
    up[i][j] = h[i][j];
    int child_cnt = 0;
    bool cut_vertex = false;
    for(int d = 0 ; d < 4 ; d++){
        int x = i + dx[d];
        int y = j + dy[d];
        if(s[x][y] != '#') continue;
        if(x == ip && y == jp) continue;
        if(mark[x][y]){
            up[i][j] = min(up[i][j] , h[x][y]);
        }
        else{
            h[x][y] = 1 + h[i][j];
            dfs(x , y , i , j);
            child_cnt++;
            up[i][j] = min(up[i][j] , up[x][y]);
            if(up[x][y] >= h[i][j]){
                cut_vertex = true;
            }
        }
    }
    if(ip == -1 && jp == -1){
        cut_vertex = child_cnt > 1;
    } 
    if(cut_vertex){
        ans.push_back({i , j});
    }
}
int main(){
    fastio;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> s[i][j];
        }
    }
    int cnt = 0;
    pii source;
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j++){
            if(s[i][j] == '#'){
                cnt++;
                source = {i , j};
            }
        }
    }
    dfs(source.first , source.second);
    if(cnt <= 2){
        cout << -1 << ln;
        return 0 ;
    }
    if(ans.size()){
        cout << 1 << ln;
    }
    else{
        cout << 2 << ln;
    }
    return 0;
}
