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
    vector<pii> a(n);
    fo(i , n){
        int x , y;
        cin >> x >> y;
        a[i] = {x , y};
    }
    fo(i , n){
        fo(j , n){
            if(i != j){
                if(a[i].first < a[j].first && a[i].second > a[j].second){
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    for(int i = 0 ; i < n - 1 ; i++){
        for(int j = 0 ; j < n - i - 1 ; j++){
            if(a[j].first > a[j + 1].first){
                swap(a[j] , a[j + 1]);
            }
            else if(a[j].first == a[j + 1].first){
                if(a[j].second > a[j + 1].second){
                    swap(a[j] , a[j + 1]);
                }
            }
        }
    }
    string ans;
    pii cord = {0 , 0};
    fo(i , n){
        while(a[i].first > cord.first){
            ans += 'R';
            cord.first++;
        }
        while(a[i].second > cord.second){
            ans += 'U';
            cord.second++;
        }
    }
    cout << "YES\n" << ans << ln;
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