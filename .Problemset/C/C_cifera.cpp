#include <iostream>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    if(k%n != 0){
        cout<<"NO";
        return 0;
    }
    else{
        int temp = k;
        int i = 0;
        while(temp > n){
            temp /= n;
            if(temp%n != 0){
                cout<<"NO";
                return 0;
            }
            i++;
        }
        cout<<"YES\n"<<i;
    }
    return 0;   
}