#include <iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    int candy[n];
    bool kid[n];
    for(int i = 0; i < n ; i++){
        cin>>candy[i];
        kid[i] = true;
    }

    int counter = 0;
    int i = 0;

    while(1){
        candy[i] -=m;
        if(kid[i]){
            if(candy[i] <= 0){
                counter++;
                kid[i] = false;
            }
        }
        if(counter == n){
            break;
        }
        i++;
        if(i == n){
            i =0;
        }
    }
    cout<<i+1;
    return 0;
}