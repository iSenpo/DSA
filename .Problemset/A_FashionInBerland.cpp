#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    int ZeroCounter = 0;

    for(int i = 0; i < n ; i++){
        cin>>a[i];
        if(a[i] == 0){
            ZeroCounter++;
        }       
    }
    if(n == 1 && a[0] == 0){
        cout<<"NO";
        return 0;
    }
    if(n == 1 && a[0] == 1){
        cout<<"YES";
        return 0; 
    }
    if(ZeroCounter != 1){
        cout<<"NO";
        return 0;
    }
    cout<<"YES";
    return 0;   
}