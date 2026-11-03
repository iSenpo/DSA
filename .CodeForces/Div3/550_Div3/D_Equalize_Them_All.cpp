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

const int N  = 2e6 + 500;
vector<int> cnt(N , 0);
//always check input!!!

void solve()
{
    int n;
    cin >> n;
    int a[n];
    int k , ind;
    int Max = 0;
    fo(i , n){ 
        cin >> a[i];
        cnt[a[i]]++;
        if(cnt[a[i]] > Max){
            Max = cnt[a[i]];
            ind = i;
            k = a[i];  
        }
    }
    vector<pair<int , pii>> ans;
    for(int i = ind - 1 ; i >= 0 ; --i){
        if(a[i] == k){
            continue;
        }
        if(a[i] > k){
            ans.push_back({2 , {i + 1 , i + 2}});
        }
        if(a[i] < k){
            ans.push_back({1 , {i + 1 , i + 2}});
        }
    }
    for(int i = ind + 1 ; i < n ; i++){
        if(a[i] == k){
            continue;
        }
        if(a[i] > k){
        ans.push_back({2 , {i + 1 , i}});
        }
        if(a[i] < k){
        ans.push_back({1 , {i + 1 , i}});
        }
    }
    cout << sz(ans) << ln;
    for(auto i : ans){
        cout << i.first << ' ' << i.second.first << ' ' << i.second.second <<ln;
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