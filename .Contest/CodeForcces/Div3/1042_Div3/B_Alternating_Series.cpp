#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; i++)
int MOD = 1e9 + 7;
const int N  = 1e5 + 500;
int arr[N];

void solve()
{

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0 ; i < n-1 ; i++){
            if(i % 2 == 0){
                cout << -1 << " ";
            }
            else{
                cout << 3 << " ";
            }
        }
        if(n%2 == 0){
            cout <<2 <<ln;
        }
        else{
            cout << -1 << ln;
        }
    }
    return 0;
}