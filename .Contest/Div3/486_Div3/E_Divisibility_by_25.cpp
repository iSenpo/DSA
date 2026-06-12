#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; ++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb(x) push_back(x)
#define mt(x , y , z) make_tuple(x , y , z)


const int INF = 1e8;
int d[10];

void recount(string s){
    memset(d , 0 , sizeof d);
    fo(i , sz(s)){
        d[s[i] - '0']++;
    }
}
int solver(string t, char c1 , char c2){
    recount(t);
    if(d[c1-'0']){d[c1-'0']--;}
    else{return INF;}
    if(d[c2-'0']){d[c2-'0']--;}
    else{ return INF;}
    int ans = 0;
    for(int i = 0 ; i < t.size() ;i++){
        if(t[i] == c1){
            int k = i;
            while(k != 0){
                ans++;
                swap(t[k] , t[k - 1]);
                k--;
            }
            break;
        }
    }
    for(int i = 1 ; i < t.size() ; i++){
        if(t[i] == c2){
            int k = i;
            while(k != 1){
                ans++;
                swap(t[k] , t[k -1]);
                k--;
            }
            break;
        }
    }
    if(t[t.size() - 1] != '0'){ return ans;}
    bool non = true;
    int k = t.size() - 1;
    while(k > 1){
        if(t[k] != '0'){
            ans += t.size() - k - 1;
            non = false;
            break;
        }
        k--;
    }
    if(non){return INF;}
    else{
        return ans;
    }
}
void solve()
{
    string s;
    cin >> s;
    reverse(all(s));
    int Min = INF;
    Min = min(Min , solver(s ,'0' , '0')); 
    Min = min(Min , solver(s ,'0' , '5')); 
    Min = min(Min , solver(s ,'5' , '2')); 
    Min = min(Min , solver(s ,'5' , '7')); 
   
    cout << (Min == INF ? -1 : Min) << ln; 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = 1;
    //t = in();
    while(t--){
        solve();
    }
    return 0;
}