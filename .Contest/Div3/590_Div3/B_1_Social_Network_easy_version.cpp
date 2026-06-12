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
   int n ,k;
   cin >> n >> k;
   int a[n];
   map<int ,bool> mark;
   fo(i , n) cin >> a[i];
   deque<int> q;
   int cnt = 0 , i = 0;
   while(i < n && cnt < k){
        if(mark[a[i]]){
            i++;
            continue;
        }
        q.push_front(a[i]);
        mark[a[i]] = true;
        i++;
        cnt++;
   }
   for(i ; i < n ; i++){
        if(mark[a[i]]){
            continue;
        }
        else{
            int x = q.back();
            q.pop_back();
            mark[x] = false;
            q.push_front(a[i]);
            mark[a[i]] = true;
        }
   }
   vector<int> ans(all(q));
   cout << ans.size() << ln;
   for(int i : ans){
    cout << i << ' ';
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