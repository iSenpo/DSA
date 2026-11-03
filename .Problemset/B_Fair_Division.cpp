#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for(int i = 0 ; i < n ; i++)
int MOD = 1e9 + 7;
const int N  = 1e5 ;
int arr[N];

void solve()
{
    int n;
    cin >> n;
    int sum = 0 , temp ,a = 0 , b =0 ;
    fo(i , n){
        cin >> temp; 
        sum+=temp;
        if(temp == 1)
            a++;
        else
            b++;
    }    
    if(a%2 == 0 && b%2 ==0){
        cout << "YES\n";
    }
    else if((a + 2*b)%2 == 0 && a!=0){
        cout << "YES\n";
    }
    else if(sum%2 == 0 && n%2 == 1){
        cout << "NO\n" ;
    }
    else if(sum%2 == 0 && n%2 == 0){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}