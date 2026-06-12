#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  = 1e5 + 500;

int main(){
    int n;
    cin >> n;
    int sum1 = 0, sum2 = 0;
    int a[n];
    for(int i = 0; i < n ; i++){
        cin >> a[i];
    }
    int pl = 0 , pr = n-1;
    int i = 0;
    while(pl != pr){
        if(i%2 == 0){
            if(a[pl] > a[pr])
                sum1 += a[pl++];
            else
                sum1 += a[pr--];
        }
        else{
            if(a[pl] > a[pr])
                sum2 += a[pl++];
            else
                sum2 += a[pr--];
        }
        i++;
    }
    if(i%2 == 0){
        if(a[pl] > a[pr])
            sum1 += a[pl++];
        else
            sum1 += a[pr--];
    }
    else{
        if(a[pl] > a[pr])
            sum2 += a[pl++];
        else
            sum2 += a[pr--];
    }

    cout << sum1 << " " << sum2;
    return 0;
}