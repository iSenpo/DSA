#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; i++)

int gcd(int a , int b){
    while(b != 0){
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t;
    cin >> t;
    while(t--){
        int n , k;
        cin >> n >> k;
        int a[n] , b[n];
        fo(i , n) cin >> a[i];
        fo(i , n) cin >> b[i];
        bool ans = true;
        fo(i , n){
            if(a[i] == b[i])
                continue;
            int diff = gcd(abs(k - a[i]) , a[i]);
            int sum = gcd(k + a[i] , a[i] );
            if(b[i] == 1){
                if(sum == 1 || diff == 1)
                    continue;
                else
                    ans = false;
            }
            ans = false;
        }
        if(ans){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}