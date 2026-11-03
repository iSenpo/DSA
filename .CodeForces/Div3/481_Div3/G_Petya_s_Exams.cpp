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
    int n , m;
    cin >> n >> m;
    int day[n + 1];
    memset(day , 0 , sizeof day);
    int s , dd , c;
    vector<pair<int , pair<int , pair<int , int>>>> d;
    for(int i = 1 ; i <= m ; i++){
        cin >> s >> dd >> c;
        d.push_back({dd , {s , {c , i}}});
        day[dd] = m + 1;
    }
    sort(all(d));
    for(int i = 0 ; i < m ; i++){
        for(int j = d[i].second.first ; j < d[i].first ; j++){
            if(day[j] != 0){
                continue;
            }
            if(d[i].second.second.first == 0){
                break;
            }
            d[i].second.second.first--;
            day[j] = d[i].second.second.second;
        }
        if(d[i].second.second.first > 0){
            cout << -1;
            return;
        }
    }
    for(int i = 1 ; i <= n ; i++){
        cout << day[i] <<' ';
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