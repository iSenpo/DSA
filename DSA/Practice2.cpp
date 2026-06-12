#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> ptr(n+1);
    for(int i = 0;i <= n ; i++){
        cin >> ptr[i];
    }
    int size = ptr[n];
    vector<int> ind(size) , val(size);
    for(int i = 0; i < size ; i++){
        cin >> ind[i];
    }
    for(int i = 0;i < size ; i++){
        cin >> val[i];
    }
    long long sum = 0;
    for(int r = 0;r < n ; r++){
        for(int j = ptr[r];j < ptr[r+1] ;j++){
            if(ind[j] <= r){
                sum += val[j];
            }
        }
    }
    cout<<sum;
}
