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
    string s;
    cin >> s;
    string t = "sa";
    vector<vector<int>> Max(26 , vector<int>(26 , 0));
    int ans = 0;
    for(int i = 0 ; i < n -1 ; ++i){
        ++Max[s[i] - 'A'][s[i+1] - 'A'];
        if(ans < Max[s[i] - 'A'][s[i+1] - 'A']){
            ans = Max[s[i] - 'A'][s[i+1] - 'A'];
            t[0] = s[i];
            t[1] = s[i + 1];
        }
    }
    cout << t << ln;
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