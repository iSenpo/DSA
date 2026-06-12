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
        int a[n];
        for(int i = 0; i < n ; i++){
            cin >> a[i];
        }
        int pl = 0 , pr = n-1 , cnt1 = 0 , cnt2 = 0 , answer = 0;
        ll sum1 = 0, sum2 = 0;
        while(pl <= pr){
            if(sum1 <= sum2){
                sum1 += a[pl++];
                cnt1++;
            }
            else{
                sum2 += a[pr--];
                cnt2++;
            }
            if(sum1 == sum2){
                answer = cnt1 + cnt2;
            }
        }
        cout<< answer << endl;
    }
    return 0;
}