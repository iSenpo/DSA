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
    string name;
    int x1 , x2 , x3;
    map<string , pair<int , pair<int , int>>> cost;
    fo(i , n){
        cin >> name >> x1 >> x2 >> x3;
        cost[name] = {x1 , {x2 , x3}};
    }
    string kala , size;
    set<string> names;
    vector<string> ans;
    map<string , ll> pay;
    fo(i , m){
        cin >> name >> kala >> size;
        if(names.find(name) == names.end()){
            ans.push_back(name);
        }
        names.insert(name);
        if(size == "small"){
            pay[name] += cost[kala].first;
        }
        if(size == "medium"){
            pay[name] += cost[kala].second.first;
        }
        if(size == "large"){
            pay[name] += cost[kala].second.second;
        }
    }
    int k = sz(names);
    fo(i , k){
        string s = ans[i];
        ll x = pay[s];
        x += 100/k;
        if((x + 1)%5 == 0){
            x++;
        }
        else if((x - 1)%5 == 0){
            x--;
        }
        cout << s << ' ' << x << ln;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
//check long long memory limit
//check int overflow