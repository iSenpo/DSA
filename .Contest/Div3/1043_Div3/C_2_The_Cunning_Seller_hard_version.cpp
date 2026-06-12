#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t;
    cin >> t;
    while(t--){
        ll n , k;
        cin >> n >> k;
        ll maxP = 0;
        ll cost = 0;
        int cnt = 0;
        while(n > 0){
            while(k * pow(3 , cnt) < n){
                cnt++;
            }
            if(pow(3 ,cnt) > n){
                cnt--;
            }
            maxP = cnt;
            n -= pow(3 , maxP);
            cost += pow(3 , maxP+1) + maxP * pow(3 , maxP - 1);
            cnt = 0;
            k--;
        }
        if(k < 0 || n < 0){
            cout << -1 << ln;
            continue;
        }
        cout << cost << ln;
    }
    return 0;
}