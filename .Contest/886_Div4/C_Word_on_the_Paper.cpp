#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  = 1e5 + 500;

int main(){
    int t;
    cin >> t;
    while(t--){
        char a[8][8];
        vector<char> output;
        for(int i = 0; i < 8 ; i++){
            for(int j = 0 ; j < 8 ; j++){
                cin >> a[i][j];
                if(a[i][j] != '.'){
                    output.push_back(a[i][j]);
                }
            }
        }
        for(int i = 0 ; i < output.size() ; i++){
            cout << output[i] ;
        }
        cout<<"\n";
    }
    return 0;
}