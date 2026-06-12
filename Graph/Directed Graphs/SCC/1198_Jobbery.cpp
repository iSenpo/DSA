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

const int N  = 2010;
//always check input!!!

vector<int> In[N] , Out[N];
bool mark[N];
vector<int> sorted;
int cnt = 1;
int color[N];


void dfs1(int v){
    mark[v] = true;
    for(int i : In[v]){
        if(!mark[i]){
            dfs1(i);
        }
    }    
    sorted.push_back(v);
}

void dfs2(int v){
    mark[v] = true;
    for(int i : Out[v]){
        if(!mark[i]){
            dfs2(i);
        }
    }
    color[v] = cnt;
}
void solve()
{
    int n;
    cin >> n;
    fo(i , n){
        int v;
        while(true){
            cin >> v;
            if(v == 0){
                break;
            }
            v--;
            In[v].push_back(i);
            Out[i].push_back(v);
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(!mark[i]){
            dfs1(i);
        }
    }
    reverse(all(sorted));

    memset(mark , false , sizeof mark);
    for(int i : sorted){
        if(!mark[i]){
            dfs2(i);
            cnt++;
        }
    }
    vector<int> ans;
    for(int i = 0 ; i < n ; i++){
        if(color[i] == cnt - 1){
            ans.pb(i + 1);
        }
    }
    sort(all(ans));
    for(int i : ans){
        cout << i << ' ';
    }
    cout << 0 << ln;
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