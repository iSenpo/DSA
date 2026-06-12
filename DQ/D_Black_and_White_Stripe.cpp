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
        string s;
        cin >> s;
        int pl = 0 , pr = k-1;
        int MaxB = 0 , Bcnt = 0;

        for(int i = 0 ; i < k ; i++){
            if(s[i] == 'B'){
                Bcnt++;
            }
        }
        MaxB = Bcnt;
        while(pr < n-1){
            if(s[pl] == 'B'){
                Bcnt--;
            }
            pr++;
            pl++;
            if(s[pr] == 'B'){
                Bcnt++;
            }
            MaxB = max(MaxB , Bcnt);
        }
        if(MaxB >= k){
            cout<< 0 <<endl;
        }
        else{
            cout<< k - MaxB << endl;
        }
    }
    return 0;
}