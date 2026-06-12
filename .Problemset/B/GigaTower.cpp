#include <iostream>
using namespace std;

int main(){
    long long n;
    cin>>n;
    int t = n;
    while(true){
        n++;
        int temp = abs(n);
        while(temp > 0){
            int d = temp % 10;
            if (d == 8){
                cout<<n-t;
                return 0;
            }
            temp /= 10;
        }

    }
    return 0;
}