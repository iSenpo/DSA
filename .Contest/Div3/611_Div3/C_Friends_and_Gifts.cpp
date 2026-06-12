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
    map<int , bool> mark;
    fo(i , n) {
        cin >> a[i];
        mark[a[i]] = true;
    }
    deque<int> valid;
    fo(i , n){
        if(!mark[i + 1]){
            valid.push_back(i + 1);
        }
    }
    fo(i , n){
        if(a[i] == 0 && !mark[i + 1]){
            if(valid.front() == i + 1){
                a[i] = valid.back();
                valid.pop_back();
            }
            else{
                a[i] = valid.front();
                valid.pop_front();
            }
        }
    }
    fo(i , n){
        if(a[i] == 0){
            if(valid.front() == i + 1){
                a[i] = valid.back();
                valid.pop_back();
            }
            else{
                a[i] = valid.front();
                valid.pop_front();
            }
        }
    }
    fo(i , n){
        cout << a[i] << ' ';
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