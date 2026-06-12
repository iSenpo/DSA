#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  = 1e5 + 500;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n , k;
        cin >> n >> k;
        int a[n];
        for (int i = 0 ; i < n ; i++){
            cin >> a[i];
        }
        sort(a , a + n);
        int counter = 1;
        int Max = 1;
        vector<int> b;

        if(n == 1){
            cout << 0 << endl;
            continue;
        }
        int efraz = 1;
        for (int i = 1 ; i < n ; i++){
            if(a[i] - a[i-1] <= k){
                counter++;
                Max = max(Max , counter);
            }
            else{
                efraz++;
                counter = 1;
                b.push_back(Max);
                Max = 1;
            }
        }
        if(b.size() == efraz){

        }
        else{
            b.push_back(Max);
        }
        sort(b.begin() , b.end());
        int ans = 0;
        for (int i = 0; i < b.size()-1 ; i++){
            ans += b[i];
        }
        cout << ans << endl;
    }
    return 0;
}
//8 3
//17 3 1 20 12 5 17 12
//1 3 5   12 12    17 17 20
// 3        2         3
// 2 3 3