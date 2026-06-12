#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'

void solve(){
    int n , x;
    cin >> n >> x;
    int a[n];
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    sort(a , a + n);
    int ans = 0;
    for(int i = n-1 ; i >=0 ; i--){
        vector<int> str;
        str.push_back(a[i]);
        while(str[str.size()-1]*str.size() < x && i >= 1){
            i--;
            str.push_back(a[i]);
        }
        if(str[str.size()-1]*str.size() >= x){
            ans++;
        }
    }
    cout << ans << ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}