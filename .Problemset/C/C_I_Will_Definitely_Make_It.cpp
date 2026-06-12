#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<int> a(n);
        for(int  i = 0; i<n ; i++){
            cin>>a[i];
        }
        int h = a[k-1];
        int index = 0;
        sort(a.begin(),a.end());
        for(int  i = 0; i<n ; i++){
            if(a[i] == h){
                index = i;
            }
        }
        //sorted is OK , index is OK
        h = a[index];
        bool end = false;
        int water = 1;
        int tm = 0;
        for(int  i = index ; i<n-1 ; i++){
            if(h+1 < water + a[i+1] - a[i]){
                end = true;
                break;
            }
            water += a[i+1] - a[i];
            h = a[i+1];
        }
        if(end){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
    }
    return 0;
}