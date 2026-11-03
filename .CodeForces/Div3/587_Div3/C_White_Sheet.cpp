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
int x11 , x12 , x21 , x22 ,x31 , x32 , y11 , y12 , y21, y22 , y31 , y32;

bool coverx2(){
    if(x21 <= x11 && x22 >= x12){
        return true;
    }
    return false;
}
bool coverx3(){
    if(x31 <= x11 && x32 >= x12){
        return true;
    }
    return false;
}
bool covery2(){
    if(y21 <= y11 && y22 >= y12){
        return true;
    }
    return false;
}
bool covery3(){
    if(y31 <= y11 && y32 >= y12){
        return true;
    }
    return false;
}
bool cover(){
    if(coverx2() && covery2()){
        return true;
    }
    if(coverx3() && covery3()){
        return true;
    }
    return false;
}
void solve()
{

    cin >> x11 >> y11 >> x12 >> y12;
    cin >> x21 >> y21 >> x22 >> y22;
    cin >> x31 >> y31 >> x32 >> y32;
    bool x = false , y = false;
    int x1 , x2 , y1 , y2;
    //
    if((x22 < x31 || x32 < x21) && (y22 < y31 || y32 < y21)){
        if(cover()){
            cout << "NO\n";
            return;
        }
    }
    else{
        x1 = min(x21 , x31);
        x2 = max(x22 , x32);
        y1 = min(y21 , y31);
        y2 = max(y22 , y32);
        if((y1 <= y11 && y2 >= y12) && (x1 <= x11 && x2 >= x12)){
            cerr << x2 << ' ' << y2 << ln;
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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