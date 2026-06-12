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

//always check input!!!
const int N  = 110;
vector<int> adj[26];
vector<int> sorted;
set<int> source;
int d[26];

void solve()
{
    int n;
    cin >> n;
    string s[n];
    fo(i , n) cin >> s[i];
    int j = 0;
    for(int i = 0 ; i < n - 1 ; i++){
        while(s[i][j] == s[i + 1][j]){
            j++;
            if(j == sz(s[i]) || j == sz(s[i + 1])){
                j = 0;
                if(sz(s[i]) > sz(s[i + 1])){
                    cout << "Impossible\n";
                    return;
                }
                break;
            } 
        }
        adj[s[i][j] - 'a'].push_back(s[i + 1][j] - 'a');
        j = 0;
    }
    for(int i = 0 ; i < 26 ; i++){
        for(int j : adj[i]){
            if(i == j) continue;
            d[j]++;
        }
    }
    for(int i = 0 ; i < 26 ; i++){
        if(d[i] == 0){
            source.insert(i);
        }
    }
    while(!source.empty()){
        int v = *source.begin();
        source.erase(source.begin());
        sorted.push_back(v);
        for(int i : adj[v]){
            if(--d[i] == 0){
                source.insert(i);
            }
        }
    }
    if(sorted.size() < 26){
        cout << "Impossible" << ln;
        return;
    }
    for(int i : sorted){
        char ch = 'a' + i;
        cout << ch ;
    }
    cout << ln;
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