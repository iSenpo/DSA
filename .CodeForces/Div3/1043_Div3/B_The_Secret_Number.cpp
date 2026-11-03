#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
void solve()
{
    string s;
    cin >> s;
    for(int i = 0; i < s.size()-1; i++){
        if(s[i] != s[i+1]){
            cout << 0 << ln;
            return;  
        }
    }
    int cnt1 = 2;
    ll n = 0;
    for(int i = 0 ; i < s.size() ; i++){
        n += (s[i] - '0') * pow(10 , s.size() - cnt1);
        cnt1++;
    }
    cerr << n;
    ll temp = n;
    vector<ll> ans;
    int cnt = 1;
    while(temp > 0){
        temp /= 10;
        if(temp + (temp * pow(10 , cnt)) == n){
            ans.push_back(temp);
            cerr << temp << "   " << temp + (temp * pow(10 , cnt));
        }
        cnt++;
    }
    if(ans.size()){
        int dig = 0;
        int temp = ans[0];
        while(ans[0] > 0){
            dig++;
            temp /= 10;
        }
        for(int i = 0 ; i < dig ; i++){

        }
    }
    cout << ans.size() << ln;
    for(int i : ans){
        cout << i << ' ';
    }
    if(ans.size()){
        cout<<ln;
    }
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