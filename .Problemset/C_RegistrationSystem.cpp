//time limit
#include <iostream>
using namespace std;

int main(){
    int n,counter;
    int i{0};
    bool print;
    cin>>n;
    string names[n];
    for(i ; i < n ; i++){
        cin>>names[i];
        counter = 0;
        print = true;
        for(int j = 0; j < i ; j++){
            if(names[i] == names[j]){
                counter++;
                print = false;
            }
        }
        if(print){
            cout<<"OK\n";
            continue;
        }
        cout<<names[i]<<counter<<"\n";
    }
    return 0;
}