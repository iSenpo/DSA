#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; ++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb(x) push_back(x)
// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z


const int N  = 1e8;

inline int in(){
    int x;
    cin >> x;
    return x;
}
void solve()
{
    int n = in();
    int a[n];
    int ans = N;
    fo(i , n) cin >> a[i];
    if(n <= 2){
        cout << 0 << ln;
        return;
    }
    else{
        for(int i : {-1 , 0 , 1}){
            for(int j : {-1 , 0 , 1}){
                int a0 = a[0] + i;
                int a1 = a[1] + j;
                int diff = a1 - a0;
                int cnt = abs(i) + abs(j);
                int prev = a1;
                for(int k = 2 ; k < n ; ++k){
                    int next = prev + diff;
                    if(abs(next - a[k]) == 1){
                        cnt++;
                    }
                    else if(abs(next - a[k]) > 1){
                        cnt = N;
                        break;
                    }
                    prev = next;
                }
                ans = min(ans , cnt);
            }
        }
    }
    if(ans == N){
        cout << -1 << ln;
        return;
    }
    cout << ans << ln;
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