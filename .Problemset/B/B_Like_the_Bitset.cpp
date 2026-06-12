#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; i++)
#define all(x) (x).begin(),(x).end()
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
    int k = in();
    string s;
    cin >> s;
    vector<int> q(n);
    int ctr = 0;
    for(int i = 0 ; i < n ; i++){
        q[i] = i + 1;
        if(s[i] == '1'){
            ctr++;
            if(ctr >= k){
                cout << "NO\n";
                return;
            }
        }
        else{
            ctr = 0;
        }
    }
    cout << "YES\n";
    int l = 0 , r = n-1;
    for(int i = 0 ;i < n ; i++){
        if(s[i] == '0'){
            cout << q[r--] << ' ';
        }
        else{
            cout << q[l++] << ' ';
        }
    }
    cout << ln;
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