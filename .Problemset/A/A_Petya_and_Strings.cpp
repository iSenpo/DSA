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

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    string s , t;
    cin >> s >> t;
    int ans = 0;
    for(int i = 0 ; i < s.size() ; i++){
        s[i] = tolower(s[i]);
        t[i] = tolower(t[i]);
        if(s[i] < t[i]){
            ans = -1;
            break;
        }
        if(s[i] > t[i]){
            ans = 1;
            break;
        }
    }
    cout << ans;
    return 0;
}