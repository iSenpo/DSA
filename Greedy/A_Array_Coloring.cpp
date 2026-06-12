#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  = 1e5 + 500;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n ;
        cin >> n;
        int a[n];
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            cin >> a[i];
            sum += a[i];
        }
        if(sum % 2 == 0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}