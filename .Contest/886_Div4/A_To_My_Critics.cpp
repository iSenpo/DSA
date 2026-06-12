#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  = 1e5 + 500;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n1 , n2 , n3;
        cin >> n1 >> n2 >> n3;
        int Max = 0;
        Max = max(Max , n1+n2);
        Max = max(Max , n1+n3);
        Max = max(Max , n3+n2);
        if(Max >= 10){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}