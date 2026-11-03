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
    cin >> n;
    int a[n];
    deque<int> q1 , q2;
    fo(i , n){
        cin >> a[i];
        q1.push_back(a[i]);
        q2.push_back(a[i]);
    } 
    vector<int> cw(a , a + n);
    sort(all(cw));
    vector<int> ccw(all(cw));
    reverse(all(ccw));
    while(q1.front() != 1){
        int x = q1.front();
        q1.pop_front();
        q1.push_back(x);
    }
    while(q2.back() != 1){
        int x = q2.back();
        q2.pop_back();
        q2.push_front(x);
    }
    vector<int> v1(all(q1)) , v2(all(q2));
    if(v1 == cw || v2 == ccw){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
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