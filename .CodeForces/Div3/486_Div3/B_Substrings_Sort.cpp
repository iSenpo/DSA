#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; ++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb(x) push_back(x)
// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int MOD = 1e9 + 7;

const int N  = 1e5 + 500;
int arr[N];

inline int in(){
    int x;
    cin >> x;
    return x;
}
void solve()
{
    int n = in();
    string s[n];
    fo(i , n){
        cin >> s[i];
    }
    for(int i = 0 ; i < n - 1 ; ++i){
        for(int j = 0 ; j < n - i - 1 ; ++j){
            if(s[j].size() > s[j + 1].size()){
                swap(s[j] , s[j + 1]);
            }
        }
    }
    fo(i , n - 1){
        int t = s[i].size();
        bool round = false;
        for(int j = 0 ; j <= s[i + 1].size() - t ; ++j){
            if(s[i + 1].substr(j , t) == s[i]){
                round = true;
                continue;
            }
        }
        if(s[i + 1] == s[i]){
            continue;
        }
        if(!round){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    fo(i , n){
        cout << s[i] << ln;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = 1;
    //t = in();
    while(t--){
        solve();
    }
    return 0;
}