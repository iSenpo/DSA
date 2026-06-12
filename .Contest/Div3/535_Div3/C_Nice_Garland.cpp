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

void solve()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    string tt = s;
    vector<vector<int>> v(3 , vector<int>(3 , 0));
    for(int i = 0 ; i < n ; i+=3){
        if(s[i] != 'R'){
            v[0][0]++;
        }
        if(s[i] != 'G'){
            v[1][0]++;
        }
        if(s[i] != 'B'){
            v[2][0]++;
        }
    }
    for(int i = 1 ; i < n ; i+=3){
        if(s[i] != 'R'){
            v[0][1]++;
        }
        if(s[i] != 'G'){
            v[1][1]++;
        }
        if(s[i] != 'B'){
            v[2][1]++;
        }
    }
    for(int i = 2 ; i < n ; i+=3){
        if(s[i] != 'R'){
            v[0][2]++;
        }
        if(s[i] != 'G'){
            v[1][2]++;
        }
        if(s[i] != 'B'){
            v[2][2]++;
        }
    }
    vector<pair<int , tuple <int , int , int>>> cost(6);
    cost[0].first = v[0][0] + v[1][1] + v[2][2];
    cost[0].second = mt(0 , 1 , 2);

    cost[1].first = v[0][0] + v[2][1] + v[1][2];
    cost[1].second = mt(0 , 2 , 1);

    cost[2].first = v[1][0] + v[0][1] + v[2][2];
    cost[2].second = mt(1 , 0 , 2);

    cost[3].first = v[1][0] + v[2][1] + v[0][2];
    cost[3].second = mt(1 , 2 , 0);

    cost[4].first = v[2][0] + v[0][1] + v[1][2];
    cost[4].second = mt(2 , 0 , 1);

    cost[5].first = v[2][0] + v[1][1] + v[0][2];
    cost[5].second = mt(2 , 1 , 0);

    sort(all(cost));
    char c[3] = {'R' , 'G' , 'B'};
    int i = get<0>(cost[0].second);
    int j = get<1>(cost[0].second);
    int k = get<2>(cost[0].second);
    int ans = 0;
    for(int t = 0 ; t < n ; t+=3){
        if(s[t] != c[i]){
            s[t] = c[i];
        }
        if(s[t + 1] != c[j]){
            s[t + 1] = c[j];
        }
        if(s[t + 2] != c[k]){
            s[t + 2] = c[k];
        }
    }
    fo(i , n){
        if(tt[i] != s[i]){
            ans++;
        }
    }
    cout << ans << ln << s << ln;
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