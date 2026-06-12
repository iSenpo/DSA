#include <iostream>
using namespace std;

int main(){
    int n[2][2];
    cin>>n[0][0]>>n[0][1]>>n[1][0]>>n[1][1];
    int d1 = abs(n[0][0] - n[1][0]);
    int d2 = abs(n[0][1] - n[1][1]);
    if(d1 == d2){
        cout<<d1;
        return 0;
    }
    else{
        cout<<max(d1,d2);
    }
    return 0;
}