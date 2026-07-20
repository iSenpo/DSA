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
    int n , a , b;
    cin >> n >> a >> b;
    int d = abs(a - b);
    int ans = 1;
    for(int i = 1 ; i <= max(a , b) ; i++){
        if(a%i == b%i && (d / i) < n){
            ans = i;
            break;
        }
    }
    vector<int> num;
    num.push_back(a);
    num.push_back(b);
    int cnt = 2;
    int temp = a;
    while(temp + ans < b && cnt < n){
        temp += ans;
        num.push_back(temp);
        cnt++;
    }
    temp = a;
    while(temp - ans >= 1 && cnt < n){
        temp -= ans;
        num.push_back(temp); 
        cnt++;
    }
    temp = b;
    while(cnt < n){
        temp += ans;
        num.push_back(temp);
        cnt++;
    }
    for(int i : num){
        cout << i << ' ';
    }
    cout << ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
//check long long memory limit
//check int overflow