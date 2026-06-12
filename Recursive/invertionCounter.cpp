#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  = 1e5 + 500;

int n;
int a[N];
int b[N];
int InvertionCounter = 0;

void MergeSort(int l, int r){
    if(r - l == 1){
        return;
    }
    int mid = (r + l) / 2;
    MergeSort(l , mid);
    MergeSort(mid , r);
    int pl = l , pr = mid , p = l;
    while(pl < mid && pr < r){
        if(a[pl] < a[pr]){
            b[p ++] = a[pl ++];
            InvertionCounter += pr - mid;
        }
        else{
            b[p ++] = a[pr ++];
        }
    }
    while(pl < mid){
        b[p ++] = a[pl ++];
        InvertionCounter += pr - mid;
    }
    while(pr < r){
        b[p ++] = a[pr ++];
    }
    for(int i = l ; i < r ; i++){
        a[i] = b[i];
    }
}
int main(){
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    MergeSort(0 , n);
    cout<<InvertionCounter;
    return 0;
}