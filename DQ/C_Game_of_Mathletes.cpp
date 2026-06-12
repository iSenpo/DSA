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
        for(int i = 0 ; i < n ; i++){
            cin >> a[i];
        }
        sort(a, a + n);
        int pl = 0, pr = n-1 , counter = 0;
        while(pl != pr && pl < pr){
            if(a[pl] + a[pr] == k){
                counter++;
                pl++;
                pr--;
            }
            if(a[pl] + a[pr] < k){
                pl++;
                continue;
            }
            if(a[pl] + a[pr] > k){
                pr--;
                continue;
            }
        }
        cout << counter << endl;
    }
    return 0;
}