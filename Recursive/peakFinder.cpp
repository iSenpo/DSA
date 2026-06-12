#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  = 1e5 + 500;
int a[N];

int find_peak(int l,int r){
    if(r - l == 1){
        return a[l];
    }
    int m = (r + l) / 2;
    if(a[m-1] > a[m]){
        find_peak(l,m);
    }
    else{
        find_peak(m,r);
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }    
    cout<<find_peak(0,n);

    return 0;
}