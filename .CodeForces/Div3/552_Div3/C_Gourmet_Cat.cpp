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

//Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday
//{0 , 1 , 4} [a];
//{2 , 6} [b];
//{3 , 5} [c];

bool week(int a , int b , int c){
    if(a >= 3 && b >= 2 && c >= 2){
        return true;
    }
    return false;
}
void solve()
{
    int a , b , c;
    cin >> a >> b >> c;
    ll ans = 0;
    while(week(a , b , c)){
        ans += 7;
        a -= 3;
        b -= 2;
        c -= 2;
    }
    int sum = 0;
    for(int i = 0 ; i < 7 ; i++){
        fo(j , 7){
            int curr = 0;
            int ta = a , tb = b , tc = c;
            for(int p = j ; p < j + 7 ; p++){
                int tj = p%7;
                if(tj == 0 || tj == 4 || tj == 1){
                    if(ta <= 0){
                        break;
                    }
                    else{
                        ta--;
                        curr++;
                    }
                }
                if(tj == 2 || tj == 6){
                    if(tb <= 0){
                        break;
                    }
                    else{
                        tb--;
                        curr++;
                    }
                }
                if(tj == 3 || tj == 5){
                    if(tc <= 0){
                        break;
                    }
                    else{
                        tc--;
                        curr++;
                    }
                }
            }
            sum = max(sum , curr);
        }
    }
    ans += sum;
    cout << ans << ln;
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