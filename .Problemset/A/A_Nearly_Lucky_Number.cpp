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

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    string s;
    cin >> s;
    int cnt = 0;
    fo(i , s.size())
        if(s[i] == '4' || s[i] == '7')
            cnt++;
    if(cnt == 4 || cnt == 7)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}