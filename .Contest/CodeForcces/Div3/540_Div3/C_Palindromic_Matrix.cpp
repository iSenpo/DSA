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

const int N  = 1005;
//always check input!!!

void solve()
{
    int n;
    cin >> n;
    int a[n * n];
    int b[n][n];
    vector<int> u;
    map<int , int> cnt;
    fo(i , n * n){
        cin >> a[i];
        if(!cnt[a[i]]){
            u.pb(a[i]);
        }
        cnt[a[i]]++;
    }
    vector<int> pr4;
    int size = (n / 2) * (n / 2);
    for(int i : u){
        while(cnt[i] >= 4 && sz(pr4) < size){
            pr4.pb(i);
            cnt[i] -= 4;
        }
    }
    if(size != sz(pr4)){
        cout << "NO\n";
        return;
    }
    int k = 0;
    fo(i , n/2){
        fo(j , n/2){
            int x = pr4[k++];
            b[i][j] = x;
            b[n - 1 -i][j] = x;
            b[i][n - 1 - j] = x;
            b[n - 1 - i][n - 1 - j] = x;
        }
    }
    if(n%2 == 1){
        vector<int> pr2;
        int cnt2 = 0 , cnt1 = 0;
        for(int i : u){
            while(cnt[i] >= 2){
                cnt[i] -= 2;
                pr2.pb(i);
                cnt2++;
            }
            if(cnt[i] == 1){
                cnt1++;
                cnt[i]--;
                b[n/2][n/2] = i;
            }
        }
        if(cnt1 != 1){
            cout << "NO\n";
            return;
        }
        if(cnt2 != n - 1){
            cout << "NO\n";
            return;
        }
        k = 0;
        fo(i , n/2){
            b[n/2][i] = pr2[k];
            b[n/2][n - 1 - i] = pr2[k];
            k++;
            b[i][n/2] = pr2[k];
            b[n - 1 - i][n/2] = pr2[k];
            k++;
        }
    }
    cout << "YES\n";
    fo(i , n){
        fo(j , n){
            cout << b[i][j] << ' ';
        }
        cout << ln;
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