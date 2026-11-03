#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int , int>
#define pll pair<ll , ll>
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; ++i)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) (int)(x).size()
#define pb(x) push_back(x)
#define	set_dec(x) cout << fixed << setprecision(x);
// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int MOD = 1e9 + 7;
const int N  = 2e5 + 10;
const int INF = 2e9 + 100;
const int MIN = -2e9 - 100;
//always check input!!!

vector<vector<int>> a , b;

int Frow(int n , int m , int Max){
    vector<int> row , col;
    map<int , int> cntR , cntC;
    int MaxR = 0 , MaxC = 0;
    int R = 0 , C = 0;
    fo(i , n){
        fo(j , m){
            if(b[i][j] == Max){
                row.push_back(i);
            }
        }
    }
    for(int i : row){
        cntR[i]++;
        MaxR = max(MaxR , cntR[i]);
    }
    for(int i = 0 ; i < sz(row) ; i++){
        if(cntR[row[i]] == MaxR){
            R = row[i];
            break;
        }
    }
    fo(j , m) b[R][j]--;

    fo(i , n){
        fo(j , m){
            if(a[i][j] == Max){
                col.push_back(j);
            }
        }
    }
    for(int i : col){
        cntC[i]++;
        MaxC = max(MaxC , cntC[i]);
    }
    for(int i = 0 ; i < sz(col) ; i++){
        if(cntC[col[i]] == MaxC){
            C = col[i];
            break;
        }
    }
    fo(i , n) b[i][C]--;

    b[R][C]++;
    int Max1 = 0;
    fo(i , n){
        fo(j , m){
            Max1 = max(Max1 , b[i][j]);
        }
    }
    return Max1;
}
int Fcol(int n , int m , int Max){
    vector<int> row , col;
    map<int , int> cntR , cntC;
    int MaxR = 0 , MaxC = 0;
    int R = 0 , C = 0;

    fo(i , n){
        fo(j , m){
            if(a[i][j] == Max){
                col.push_back(j);
            }
        }
    }
    for(int i : col){
        cntC[i]++;
        MaxC = max(MaxC , cntC[i]);
    }
    for(int i = 0 ; i < sz(col) ; i++){
        if(cntC[col[i]] == MaxC){
            C = col[i];
            break;
        }
    }
    fo(i , n) a[i][C]--;

    fo(i , n){
        fo(j , m){
            if(a[i][j] == Max){
                row.push_back(i);
            }
        }
    }
    for(int i : row){
        cntR[i]++;
        MaxR = max(MaxR , cntR[i]);
    }
    for(int i = 0 ; i < sz(row) ; i++){
        if(cntR[row[i]] == MaxR){
            R = row[i];
            break;
        }
    }
    fo(j , m) a[R][j]--;

    

    a[R][C]++;
    int Max1 = 0;
    fo(i , n){
        fo(j , m){
            Max1 = max(Max1 , a[i][j]);
        }
    }
    return Max1;
}
void solve()
{
    int n , m;
    cin >> n >> m;
    a.clear();
    a.resize(n , vector<int>(m));
    b.clear();
    b.resize(n , vector<int>(m));
    int Max = 0;
    fo(i , n){
        fo(j , m){
            cin >> a[i][j];
            b[i][j] = a[i][j];
            Max = max(Max , a[i][j]);
        }
    }
    
    cout << min(Frow(n , m , Max) , Fcol(n , m , Max)) << ln;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
