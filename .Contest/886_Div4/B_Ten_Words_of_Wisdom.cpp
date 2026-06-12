#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  = 1e5 + 500;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n] , b[n];
        int Max = 0;
        int Index = 0;
        for(int i = 0; i < n ; i++){
            cin >> a[i] >> b[i];
            if(a[i] <= 10){
                if(Max < b[i]){
                    Max = b[i];
                    Index = i+1;
                }
            }
        }

        cout << Index << endl;
    }
    return 0;
}