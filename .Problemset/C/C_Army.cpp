#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ranks[n-1];
    for(int i = 0; i < n-1 ; i++){
        cin>>ranks[i];
    }
    int a,b;
    cin>>a>>b;
    int sum = 0;
    for(int i = a-1 ; i < b-1 ; i++){
        sum+=ranks[i];
    }
    cout<<sum;
    return 0;
}