#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    char temp;
    for(int i = 0 ; i<n-1; i++){
        cin>>a[i]>>temp;
    }
    cin>>a[n-1];

    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < n ; j++){
            if(!((a[i]%a[j] == 0) || (a[j]%a[i] == 0))){
                cout<<"NOT FRIENDS";
                return 0;
            }
        }
    }
    cout<<"FRIENDS";
    return 0;
}