#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int , int>
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; ++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb(x) push_back(x)

//always check input!!!


void solve()
{   
    map<int , int> p2;
    int a , b , c;
    cin >> a >> b >> c;
    for(int t : {a , b , c}){
        for(int i = 30 ; i >= 0 ; i--){
            int j = 1 << i;
            while(t >= j){
                p2[j]++;
                t -= j;
            }
        }
    }
    for(int i = 0 ; i < 31 ; ++i){
        int j = 1 << i;
        if(p2[j] == 0){
            continue;
        }
        if(p2[j]%2 == 0){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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