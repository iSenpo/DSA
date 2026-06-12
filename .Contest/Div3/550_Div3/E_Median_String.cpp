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

const int N  = 2e5 + 10;
//always check input!!!

void solve()
{
    int n;
    cin >> n;
    string s , t;
    cin >> s >> t;
    int n1 , n2 , n3;
    vector<char> k(n , 0);
    for(int i = n - 1 ; i >= 0 ; --i){
        if(s[i] == t[i]){
            k[i] = s[i];
        }
        if(s[i] > t[i]){
            n1 = 'z' - s[i];
            n2 = t[i] - 'a';
            n3 = s[i] + (n1 + n2)/2;
            while(n3 > 122){
                n3 = abs(122 - n3);
            }
            char temp = 'a' + n3;
            k[i] = temp;
        }
        if(s[i] < t[i]){
            n1 = t[i] - s[i];
            char temp = 'a' + n1/2;
            k[i] = temp;
        }
    }
    fo(i , n){
        cout << k[i];
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