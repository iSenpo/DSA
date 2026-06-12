#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; i++)
int MOD = 1e9 + 7;
const int N  = 1e5 + 500;
int arr[N];

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int sum = 0;
    for(int i = 0 ; i < n ; i++){
        if(s[i] == '@'){
            sum++;
        }
        if(i > 0){
            if(s[i] == '*' && s[i-1] == '*'){
                break;
            }
        }
    }
    cout << sum << ln;
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