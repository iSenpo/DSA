#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    int answer[n];
    for(int i = 0 ; i<n ; i++){
        cin>>a[i];
    }
    for(int i = 0; i<n ; i++){
        answer[i] = -1;
        for(int j = i; j< n ; j++){
            if(a[j] < a[i]){
                answer[i] = a[j];
                break;
            }
        }
    }
    for(int i = 0 ; i<n ; i++){
        cout<<answer[i] << "\t";
    }
    return 0;
}
