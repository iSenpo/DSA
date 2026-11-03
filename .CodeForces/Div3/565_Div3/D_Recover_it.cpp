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

const int N  = 2750131 + 1;
//always check input!!!
//2750131
vector<ll> p;
bool not_prime[N];
void linear_sieve() {
    for(int i = 2; i <= N; i++){
        if(!not_prime[i]){
            p.push_back(i);
        }
        for(int pr : p){
            ll x = 1LL * pr * i;
            if(x > N){
                break;
            }
            not_prime[x] = true;
            if(i % pr == 0){
                break;
            }
        }
    }
}
int GreatestDivisor(int n){
    for(int i = 0; p[i] <= sqrt(n) ; i++){
        if(n%p[i] == 0){
            return (n/p[i]);
        }
    }
    return -1;
}

void solve()
{
    int n;
    cin >> n;
    int a[2 * n];
    fo(i , 2 * n){
        cin >> a[i];
    }
    sort(a , a + (2*n));
    vector<int> ans , primes;
    map<int , bool> mark;
    fo(i , 2 * n){
        if(binary_search(all(p) , a[i])){
            primes.push_back(a[i]);
        }
        else{
            
        }
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