//time limit!!
#include <iostream>

using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    int a[2*n];
    int table = 0;
    int max = 0;
    bool pair[n];
    int k = 0;
    for(int i = 0; i < 2*n ; i++){
        cin>>a[i];
        pair[a[i]] = true;
        for(int j = 0; j < i ;j++){
            if(a[i] == a[j]){
                pair[a[i]] = false;
            }
        }
        if(pair[a[i]]){
            table++;
        }
        if(table > max){
            max = table;
        }
        if(!pair[a[i]]){
            table--;
        }
    }
    cout<<max;
    return 0;
}