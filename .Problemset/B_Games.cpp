#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n][2];
    for(int i = 0; i < n ; i++){
        cin>>a[i][0]>>a[i][1];
    }
    int counter = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < n ; j++){
            if(a[i][0] == a[j][1]){
                counter++;
            }
        }
    }
    cout<<counter;
    return 0;
}