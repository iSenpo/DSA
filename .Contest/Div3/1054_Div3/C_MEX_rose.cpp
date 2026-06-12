#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; i++)
#define all(x) (x).begin(),(x).end()
int MOD = 1e9 + 7;
const int N  = 2e5;
int arr[N];

inline int in(){
    int x;
    cin >> x;
    return x;
}
void solve()
{
    int n = in();
    int k = in();
    int a[n];
    int cnt = 0;
    vector<bool> mark(N , false);
    fo(i , n){
        cin >> a[i];
        mark[a[i]] = true;
        if(a[i] == k){
            cnt++;
        }
    }
    int cnt2 = 0;
    fo(i , k){
        if(!mark[i]){
            cnt2++;
        }
    }
    cout << max(cnt , cnt2) << ln;

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = in();
    while(t--){
        solve();
    }
    return 0;
}