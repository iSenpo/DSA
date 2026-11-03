#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for(int i = 0 ; i < n ; i++)
int MOD = 1e9 + 7;
const int N  = 1e5 + 500;
int arr[N];

void solve(){
    int n;
    cin >> n;
    int Max = 0 , Min = N;
    fo(i , n){
        cin >> arr[i];
        if(arr[i] > Max){
            Max = arr[i];
        }
        if(arr[i] < Min){
            Min = arr[i];
        }
    }
    int L = 0 , R = n-1;
    fo(i , n) {
        if(arr[i] == Max || arr[i] == Min){
            L = i + 1;
            break;
        }
    }
    for(int i = n-1 ; i >=0 ; i--){
        if(arr[i] == Max || arr[i] == Min){
            R = i + 1; 
            break;
        }
    }
    
    int diff = R - L;
    int bz1 = L , bz2 = n - R + 1;
    if(bz1 == bz2){
        if(diff < bz2){
            cout << bz1 + diff << endl;
        }
        else{
            cout << bz1 * 2 << endl;
        }
    }
    if(bz1 < bz2){
        if(diff < bz2){
            cout << bz1 + diff << endl;
        }
        else{
            cout << bz1 + bz2 << endl;
        }
    }
    if(bz1 > bz2){
        if(diff < bz1){
            cout << bz2 + diff << endl;
        }
        else{
           cout << bz1 + bz2 << endl;
        }
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