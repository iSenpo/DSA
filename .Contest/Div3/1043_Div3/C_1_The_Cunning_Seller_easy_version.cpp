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
        ll n;
        cin >> n;
        ll maxP = 0;
        ll cost = 0;
        while(n > 0){
            maxP = log(n)/log(3);
            if(pow(3 , maxP + 1) <= n){
                maxP++;
            }
            cost += pow(3 , maxP + 1) + maxP * pow(3 , maxP -1);
            n -= pow(3 , maxP);
        }
        cout << cost << ln;
    }
    return 0;
}