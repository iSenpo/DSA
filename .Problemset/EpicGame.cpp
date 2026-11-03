#include <iostream>
using namespace std;

int gcd(int a, int b){
    for(int i = min(a,b); i>= 1; i--){
        if(a%i == 0 && b%i == 0){
            return i;
        }
    }
    return 1;
}

int main(){
    int a,b,n,temp;
    cin>>a>>b>>n;
    while(1){    
            temp = gcd(a,n);
            if(n < temp){
                cout<<1;
                break;
            }
            n -= temp;
            temp = gcd(b,n);
            if(n < temp){
                cout<<0;
                break;
            }
            n -= temp;
    }
    return 0;
}