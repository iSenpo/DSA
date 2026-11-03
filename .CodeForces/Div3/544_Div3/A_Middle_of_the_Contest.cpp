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
    string s;
    cin >> s;
    string t;
    cin >> t;
    int s1 = s[0] - '0';
    int t1 = t[0] - '0';
    int s2 = s[1] - '0';
    int t2 = t[1] - '0';
    int n1 = s1*10 + s2;
    int n2 = t1*10 + t2;
    int h = n2 - n1;
    int s3 = s[3] - '0';
    int t3 = t[3] - '0';
    int s4 = s[4] - '0';
    int t4 = t[4] - '0';
    int n3 = s3*10 + s4;
    int n4 = t3*10 + t4;
    int m = n4 - n3;
    m += h * 60;
    m /= 2;
    while(m >= 60){
        n1++;
        m -= 60;
    }
    n3 += m;
    while(n3 >= 60){
        n1++;
        n3 -= 60;
    }
    string p = "00:00";
    p[0] = n1/10 + '0';
    p[1] = n1%10 + '0';
    p[3] = n3/10 + '0';
    p[4] = n3%10 + '0';
    cout << p << ln;
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