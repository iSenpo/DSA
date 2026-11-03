#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll t;
    cin>>t;
    while(t--){
        ll n , k;
        cin >>n >> k;
        ll x = (n + k - 1) / k;
        ll sum = k * x ;
        ll ans = (sum + n -1) / n;
        cout<<ans<<endl;
    }  
    return 0;
}