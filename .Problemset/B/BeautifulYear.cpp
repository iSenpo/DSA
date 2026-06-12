#include <iostream>
using namespace std;
int main(){
    int y;
    cin >> y;
    while(true){
        y++;
        int temp = y;
        bool used[10] = {false};
        bool uniqe = true;
        
        while(temp > 0){
            int d = temp % 10;
            if(used[d]){
                uniqe = false;
                break;
            }
            used[d] = true;
            temp /= 10;
        }
        if(uniqe){
            cout << y;
            break;
        }
    }
return 0;
}