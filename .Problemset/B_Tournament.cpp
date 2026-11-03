#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  = 1e5 + 500;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k,j;
        cin >> n >> j >> k;
        vector<int> a(n);
        for(int i = 0; i< n ; i++){
            cin >> a[i];
        }
        int temp = a[j-1];
        sort(a.begin() , a.end());
        for(int i = 0; i< n ; i++){
            if(a[i] == a[i+1]){
                a[i] = 0;
            }
        }
        sort(a.begin() , a.end());
        if(a[n-k] <= temp){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
        
    }
    return 0;
}