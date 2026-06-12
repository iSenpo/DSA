#include <iostream>
using namespace std;

int main(){
    int counter = 0;
    long long n,x;
    cin>>n>>x;
    for(int i = 1; i<= n; i++){
        if(x%i == 0){
            long long j = x/i;
            if(j <= n){
                counter++;
            }
        }
    }
    cout<<counter;
    return 0;
}