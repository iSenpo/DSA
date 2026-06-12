#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'

//my solve :(
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    n = s.size() -1;
    if(s[0] == '2' && s[1] == '0' && s[2] == '2' && s[3] == '0'){
        cout << "YES\n";
        return;
    }
    if(s[0] == '2' && s[1] == '0' && s[2] == '2' && s[n] == '0'){
        cout << "YES\n";
        return;
    }
    if(s[0] == '2' && s[1] == '0' && s[n-1] == '2' && s[n] == '0'){
        cout << "YES\n";
        return;
    }
    if(s[0] == '2' && s[n-2] == '0' && s[n-1] == '2' && s[n] == '0'){
        cout << "YES\n";
        return;
    }
    if(s[n-3] == '2' && s[n-2] == '0' && s[n-1] == '2' && s[n] == '0'){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
    return;
}
//Rank1 :
int input(){
    int x;
    cin >> x;
    return x;
}
void solve2(){
    int n = input();
    string s;
    cin >> s;
    const string t = "2020";
    bool check = false;
    for(int i = 0 ; i < 4 ; i++){
        if(s.substr(0 , i) == t.substr(0 , i) && s.substr(n-4+i) == t.substr(i)){
            check = true;
        }
    }
    cout << (check ? "YES\n" : "NO\n");
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t;
    cin >> t;
    while(t--){
        solve2();
    }
    return 0;
}